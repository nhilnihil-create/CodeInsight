#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool inc = true;
    int a[200003];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
        if(i > 0 && a[i] <= a[i - 1]) inc = false;
    }
    if(inc){
        cout << 1 << endl;
        return 0;
    }
    int now = 131072;
    int mid = now / 2;
    while(mid > 0){
        map<int, int> mp;
        int s[200005] {0};
        int p = 0;
        for(int i = 0; i < n; i++){
            int insrt = lower_bound(s, s + p, a[i]) - s;
            if(insrt == p && (i == 0 || a[i] > a[i - 1])){
                s[p] = a[i];
                mp[a[i]] = 0;
                p++;
            }
            else if(insrt == p || s[insrt] != a[i]){
                s[insrt] = a[i];
                mp[a[i]] = 1;
                p = insrt + 1;
            }
            else{
                int l = a[i];
                while(true){
                    mp[l]++;
                    if(mp[l] != now){
                        s[insrt] = l;
                        p = insrt + 1;
                        break;
                    }
                    if(l == 0){
                        p = 1;
                        break;
                    }
                    if(insrt == 0 || s[insrt - 1] != l - 1){
                        mp[l - 1] = 0;
                    }
                    else{
                        insrt--;
                    }
                    l--;
                }
            }
        }
        if(mp[0] < now) now -= mid;
        else now += mid;
        mid /= 2;
    }
    if(now == 1){
        cout << 2 << endl;
        return 0;
    }
    map<int, int> mp;
    int s[200005] {0};
    int p = 0;
    for(int i = 0; i < n; i++){
        int insrt = lower_bound(s, s + p, a[i]) - s;
        if(insrt == p && (i == 0 || a[i] > a[i - 1])){
            s[p] = a[i];
            mp[a[i]] = 0;
            p++;
        }
        else if(insrt == p || s[insrt] != a[i]){
            s[insrt] = a[i];
            mp[a[i]] = 1;
            p = insrt + 1;
        }
        else{
            int l = a[i];
            while(true){
                mp[l]++;
                if(mp[l] != now){
                    s[insrt] = l;
                    p = insrt + 1;
                    break;
                }
                if(l == 0){
                    p = 1;
                    break;
                }
                if(insrt == 0 || s[insrt - 1] != l - 1){
                    mp[l - 1] = 0;
                }
                else{
                    insrt--;
                }
                l--;
            }
        }
    }
    if(mp[0] >= now) now++;
    cout << now << endl;
}