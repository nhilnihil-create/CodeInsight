#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll h,w,n;
    cin >> h >> w >> n;
    ll sr,sc;
    cin >> sr >> sc;
    --sr;   --sc;
    string s,t;
    cin >> s >> t;
    ll ltan = 0;
    ll rtan = w-1;
    for(i = n-1;i >= 0;--i){
        if(t.at(i) == 'L') rtan = min(w-1, rtan + 1);
        if(t.at(i) == 'R') ltan = max(0ll,ltan - 1);
        if(s.at(i) == 'L') ltan += 1;
        if(s.at(i) == 'R') rtan -= 1;
        if(rtan < ltan){
            cout << "NO" << endl;
            return 0;
        }
    }
    if(sc < ltan || sc > rtan){
        cout << "NO" << endl;
        return 0;
    }
    ll utan = 0;
    ll dtan = h-1;
    for(i = n-1;i >= 0;--i){
        if(t.at(i) == 'U') dtan = min(h-1, dtan + 1);
        if(t.at(i) == 'D') utan = max(0ll, utan - 1);
        if(s.at(i) == 'U') utan += 1;
        if(s.at(i) == 'D') dtan -= 1;
        if(dtan < utan){
            cout << "NO" << endl;
            return 0;
        }
    }
    if(sr < utan || sr > dtan){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}