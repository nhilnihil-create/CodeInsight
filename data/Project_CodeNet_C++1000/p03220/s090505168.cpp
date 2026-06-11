#include <bits/stdc++.h> //C++の機能を「全て」読み込むための命令
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll inf=1e18;
const int N=2e5+10;
ll factorial(ll x){
    if(x==0||x==1) return 1;
    return x*factorial(x-1);
}

int main(){
    int n,t,a;
    cin >> n >> t >> a;
    vector<int> h(n);
    rep(i,n) cin >> h[i];

    double t_ave=0;
    double dif=0;
    double dif_min = 0;
    int idx=1;
    rep(i,n){
        t_ave = t - 0.006*h[i];
        dif = abs(t_ave - a);
        if(i==0) dif_min = dif;
        if(dif<dif_min){
            dif_min =  dif;
            idx = i+1;
        }
    }

    cout<<idx<<endl;
    return 0;
}