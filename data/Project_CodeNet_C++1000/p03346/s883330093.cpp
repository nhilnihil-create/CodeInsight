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
    int n,cnt=1,ans=1; cin>>n;
    vector<int> p(n,0),pos(n+1,0);
    rep(i,n){
        cin>>p[i];
        pos[p[i]]=i;
    }
    for(int i=1;i<n;i++){
        if(pos[i]<pos[i+1]) cnt++;
        else cnt=1;
        ans=max(ans,cnt);
    }
    cout<<n-ans<<endl;
}