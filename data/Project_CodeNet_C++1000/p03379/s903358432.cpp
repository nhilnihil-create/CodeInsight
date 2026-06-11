#include<bits/stdc++.h>
#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define per(i,n,j) for(int i=(n);i>=(j);i--)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

int n;

int main(){
    cin>>n;
    vector<int> x(n),y(n);
    rep(i,0,n){
        cin>>x[i];
        y[i]=x[i];
    }
    sort(y.begin(),y.end());
    int num=(1+n)/2-1;
    rep(i,0,n){
        if(x[i]<=y[num]) cout<<y[num+1]<<"\n";
        else if(x[i]>=y[num+1]) cout<<y[num]<<"\n";
    }
    return 0;
}
