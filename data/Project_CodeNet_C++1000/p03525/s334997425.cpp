//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    int n; cin>>n;
    vector<int> d(n,0),c(13,0);
    rep(i,n){
        cin>>d[i];
        c[d[i]]++;
    }
    if(c[0]>0){
        cout<<0<<endl;
        return 0;
    }
    rep(i,12){
        if(c[i+1]>2){
            cout<<0<<endl;
            return 0;
        }
    }
    vector<int> data,r;
    rep(i,12){
        if(c[i+1]==2){
            data.push_back(i+1);
            data.push_back(24-i-1);
        }
        else if(c[i+1]==1) r.push_back(i+1);
    }
    data.push_back(0);
    int ans=0,k=r.size(),l=data.size();
    if(k==0){
        ans=30;
        rep(i,l)rep(j,l){
            if(i==j) continue;
            int cur=abs(data[i]-data[j]);
            ans=min(ans,min(cur,24-cur));
        }
        cout<<ans<<endl;
    }
    else{
        rep(i,k) data.push_back(0);
        rep(i,(1<<k)){
            int cur=30;
            rep(j,k){
                if(i&(1<<j)) data[l+j]=r[j];
                else data[l+j]=24-r[j];
            }
            rep(I,l+k)rep(J,l+k){
                if(I==J) continue;
                int cu=abs(data[I]-data[J]);
                cur=min(cur,min(cu,24-cu));
            }
            ans=max(ans,cur);
        }
        cout<<ans<<endl;
    }
}
