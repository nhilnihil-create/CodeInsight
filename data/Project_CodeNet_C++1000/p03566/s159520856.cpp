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

int main(){
    int n;
    cin>>n;
    vector<int> t(n+1),v(n+1);
    t[0]=0;
    v[n]=0;
    rep(i,n) cin>>t[i+1];
    rep(i,n) cin>>v[i];
    rep(i,n) t[i+1]+=t[i];

    double curt=0;
    double curv=0;
    double ans=0;
    rep(i,2*t[n]){
        auto it=upper_bound(t.begin(),t.end(),curt);
        int next=(it-t.begin());
        bool flag=1;
        rep(j,next,n+1){
            if(curv-v[j]==t[j]-curt){
                flag=0;
                break;
            }
        }if(flag){
            if(v[--next]==curv){
                curt+=0.5;
                ans+=curv*0.5;
            }
            else{
                curt+=0.5;
                ans+=(2*curv+0.5)*0.25;
                curv+=0.5;
            }
        }
        else{
            curt+=0.5;
            ans+=(2*curv-0.5)*0.25;
            curv-=0.5;
        }
    }
    cout<<setprecision(9)<<ans<<endl;
}

