#include <bits/stdc++.h>

#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n,s) for(int i=(s);i<(n);i++)
#define rrep(i,n) for(int i=(n-1);i>=0;i--)
#define rreps(i,n,s) for(int i=s;i>=n;i--)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

using ll = long long;
using namespace std;
constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int MOD = 1000000007;

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
int n;
cin>>n;
vector<int>t(n),x(n),y(n);
rep(i,n){
    cin>>t[i]>>x[i]>>y[i];
}
int _t=0,_x=0,_y=0;
bool ok=true;
rep(i,n){
    int dt=t[i]-_t;
    int dist=abs(x[i]-_x)+abs(y[i]-_y);
    if(dt%2==dist%2&&dist<=dt){
        _t=t[i],_x=x[i],_y=y[i];
        continue;
    }
    ok=false;
    break;    
}
if(ok){
    cout<<"Yes"<<endl;
}
else{
    cout<<"No"<<endl;
}
return 0;
}