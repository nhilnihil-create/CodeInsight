#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;
vector <int> a;

bool check(int x){
    map <int, int> cnt;
    for(int i = 1 ; i < n ; i++){
        if(a[i] > a[i - 1]) continue;
        while(cnt.size() && a[i] < cnt.rbegin()->first){
            cnt.erase(--cnt.end());
        }
        int cur = a[i];
        while(cur > 0 && cnt[cur] == x) cur--;
        if(cur == 0) return 0;
        cnt[cur]++;
        while(cnt.size() && cur < cnt.rbegin()->first){
            cnt.erase(--cnt.end());
        }
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for(auto &i : a) cin >> i;
    bool ok = 1;
    for(int i = 1 ; i < n ; i++){
        ok &= (a[i] > a[i - 1]);
    }
    if(ok) finish(1);
    int l = 1, r = n;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout << l + 1 << endl;
}
