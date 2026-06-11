#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n;
    cin >> n;
    string ss,si;
    cout << 0 << endl;
    cin >> ss;
    if(ss == "Vacant") return 0;
    cout << n-1 << endl;
    cin >> si;
    if(si == "Vacant") return 0;
    ll sup = 0, inf = n-1;
    while(true){
        ll tmp = (sup+inf)/2;
        cout << tmp << endl;
        string s;
        cin >> s;
        if(s == "Vacant") return 0;
        ll m = tmp - sup + 1;
        if(m%2){
            if(s == ss){
                sup = tmp;
                ss = s;
            }else{
                inf = tmp;
                si = s;
            }
        }else{
            if(s == ss){
                inf = tmp;
                si = s;
            }else{
                sup = tmp;
                ss = s;
            }
        }
    }

    return 0;
}
