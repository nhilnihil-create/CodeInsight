#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define int long long
#define double long double
#define mod 1000000007
#define F first
#define S second
#define P pair<long long,long long>
#define all(a) a.begin(),a.end()
#define INF 1000000000000000000
#define endl '\n'
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

signed main(){
    int n; cin>>n;
    vector<int> a(n),sum(n+1,0);
    rep(i,n){
        cin>>a.at(i);
        sum.at(i+1)=sum.at(i)+a.at(i);
    }
    int ans=INF;
    for(int i=0; i<=n; i++){
        int l=0,h=i;
        while(h-l>1){
            int mid=l+(h-l)/2;
            if(sum.at(mid)>=sum.at(i)-sum.at(mid)){
                h=mid;
            }else{
                l=mid;
            }
        }
        int p=sum.at(l),q=sum.at(i)-sum.at(l),p2=sum.at(h),q2=sum.at(i)-sum.at(h);
        int lmin=min(p,q),lmax=max(p,q);
        if(abs(p2-q2)<abs(p-q)){
            lmin=min(p2,q2);
            lmax=max(p2,q2);
        }
        int l2=i,h2=n;
        while(h2-l2>1){
            int mid=l2+(h2-l2)/2;
            if(sum.at(mid)-sum.at(i)>=sum.at(n)-sum.at(mid)){
                h2=mid;
            }else{
                l2=mid;
            }
        }
        int r=sum.at(l2)-sum.at(i),s=sum.at(n)-sum.at(l2),r2=sum.at(h2)-sum.at(i),s2=sum.at(n)-sum.at(h2);
        int rmin=min(r,s),rmax=max(r,s);
        if(abs(r2-s2)<abs(r-s)){
            rmin=min(r2,s2);
            rmax=max(r2,s2);
        }
        int tmp=max(lmax,rmax)-min(lmin,rmin);
        chmin(ans, tmp);
    }
    cout<<ans<<endl;
}