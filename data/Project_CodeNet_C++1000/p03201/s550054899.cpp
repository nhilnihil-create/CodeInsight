#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;
vector <int> a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for(auto &i : a) cin >> i;
    sort(a.begin(), a.end());
    int ans = 0;
    for(int i = 30 ; i >= 0 ; i--){
        n = a.size();
        int cur = (1 << i);
        int l = 0, r = n - 1;
        vector <int> taken(n);
        while(l < r){
            if(a[l] + a[r] < cur) l++;
            else if(a[l] + a[r] > cur) r--;
            else{
                ans++;
                taken[l] = taken[r] = 1;
                l++; r--;
            }
        }
        vector <int> b;
        for(int i = 0 ; i < n ; i++){
            if(taken[i]) continue;
            b.push_back(a[i]);
        }
        a = b;
    }
    cout << ans << endl;
}
