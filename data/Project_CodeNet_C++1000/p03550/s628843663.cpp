#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
 
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
const int mod=1e9+7;

double kjri[100001];

void make(){
    kjri[0]=0;
    rep(i,1,100001){
        kjri[i]=kjri[i-1]+log10(i);
    }
}

int main(){
    int n,z,w;cin>>n>>z>>w;
    int a[n];rep(i,n)cin>>a[i];
    if(n==1){
        cout<<abs(a[n-1]-w)<<endl;exit(0);
    }
    cout<<max(abs(a[n-1]-a[n-2]),abs(a[n-1]-w))<<endl;
}