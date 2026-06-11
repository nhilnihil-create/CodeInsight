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

int main() {
    int n,ans=0; cin>>n;
    vector<int> m(101,0);
    for(int i=2;i<=n;i++){
        int q=i;
        for(int j=2;j<=n;j++){
            while(q%j==0){
                q/=j;
                m[j]++;
            }
        }
    }
    int c74=0,c24=0,c14=0,c4=0,c2=0;
    rep(i,101){
        if(m[i]>=74) c74++;
        if(m[i]>=24) c24++;
        if(m[i]>=14) c14++;
        if(m[i]>=4) c4++;
        if(m[i]>=2) c2++;
    }
    ans+=c74;
    ans+=c14*(c4-1);
    ans+=c24*(c2-1);
    ans+=c4*(c4-1)/2*(c2-2);
    cout<<ans<<endl;
}