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
    int n,ans=0; cin>>n;
    for(int i=3;i<=n;i+=2){
        int cnt=0;
        for(int j=1;j*j<=i;j++)
        if(i%j==0) cnt+=2-(j*j==i);
        if(cnt==8) ans++;
    }
    cout<<ans<<endl;
}
