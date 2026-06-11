#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb emplace_back
#define INF (1LL<<60)

int s(int n){
    stringstream ss;
    ss<<n;
    string s = ss.str();
    int ret = 0;
    for(char elm:s){
        ret += elm-'0';
    }
    return ret;
}

double f(int n){
    return (double)n/s(n);
}

signed main(){
    int k;
    cin>>k;
    int d = 1;
    int t = 1;
    while(k--){
        cout<<t<<'\n';
        if(f(t+d)>f(t+d*10))d*=10;
        t+=d;
    }
}
