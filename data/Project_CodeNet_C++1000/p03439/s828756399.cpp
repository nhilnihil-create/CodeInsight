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
    string a,b,c;
    cout << 0 << endl;
    cin >> a;
    if(a == "Vacant") return 0;
    cout << (n-1)/2 << endl;
    cin >> b;
    if(b == "Vacant") return 0;
    cout << (n+1)/2 << endl;
    cin >> c;
    if(c == "Vacant") return 0;
    ll sup, inf;
    string ss, si;
    if((n+1)/2%2 == 0){
        if(a == b){
            sup = 0;
            inf = (n-1)/2;
            ss = a;
            si = b;
        }else{
            sup = (n+1)/2;
            inf = n;
            ss = c;
            si = a;
        }
    }else{
        if(a == b){
            sup = (n+1)/2;
            inf = n;
            ss = c;
            si = a;
        }else{
            sup = 0;
            inf = (n-1)/2;
            ss = a;
            si = b;
        }
    }
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
