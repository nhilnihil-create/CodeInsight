#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    double J=0,B=0;
    ll n;cin >>n;
    for (int i = 0; i < n; ++i) {
        double x;cin >>x;
        string u;cin >>u;
        if(u=="JPY")J+=x;
        else B+=x;
    }
    B*=380000;
    double ans=J+B;
    cout <<ans <<endl;
    return 0;
}