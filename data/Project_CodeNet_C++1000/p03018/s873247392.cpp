#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    string s;
    cin >> s;
    ll n = s.size();
    i = 0;
    ll ans = 0;
    ll tmp = 0;
    while(i+1 < n){
        if(s.at(i) == 'A'){
            ++tmp;
            ++i;
        }else if(s.substr(i,2) == "BC"){
            ans += tmp;
            i += 2;
        }else{
            tmp = 0;
            ++i;
        }
    }
    cout << ans << endl;
    return 0;
}