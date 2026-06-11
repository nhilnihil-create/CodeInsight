#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
const ll MOD = 1e9+7; ll LLINF = 1LL << 60; int INF = INT_MAX;

//

int main(){
    int n; cin>>n;
    vector<long double> x(n);
    vector<string> c(n);
    rep(i,0,n) cin>>x[i]>>c[i];
    long double sum=0;
    rep(i,0,n){
        if(c[i]=="JPY") sum+=x[i];
        else sum+=x[i]*380000;
    }
    cout<<sum<<endl;
}