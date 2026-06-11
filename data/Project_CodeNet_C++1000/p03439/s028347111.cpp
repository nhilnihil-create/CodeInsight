#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n;

int main(void){
    cin >> n;
    lli l, r;
    l = 0;
    r = n-1;
    string ls, rs;
    cout << l << endl << flush;
    cin >> ls;
    if(ls == "Vacant") return 0;
    cout << r << endl << flush;
    cin >> rs;
    if(rs == "Vacant") return 0;
    lli x;
    rep(i, 18){
        string s;
        x = (l+r)/2;
        cout << x << endl << flush;
        cin >> s;
        if(s == "Vacant") return 0;
        if((x-l)%2 == 0 && s != ls || (x-l)%2 == 1 && s == ls){
            r = x;
            rs = s;
        }else{
            l = x;
            ls = s;
        }
    }
    return 0;
}
