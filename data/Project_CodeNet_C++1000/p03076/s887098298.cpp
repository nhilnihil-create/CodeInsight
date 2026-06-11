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
	vector<int> a(5);
    rep(i,5) cin>>a[i];
    int ans=0,cnt=0;
    rep(i,5){
        ans+=(a[i]+9)/10*10;
        if(a[i]%10) cnt=max(cnt,10-a[i]%10);
    }
    cout<<ans-cnt<<endl;
}