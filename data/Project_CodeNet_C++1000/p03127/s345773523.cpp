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

int gcd(int a,int b){
    int temp;
    while(b>0){
        temp=a;
        a=b;
        b=temp%b;
    }
    return a;
}

int main(){
    int n,ans; cin>>n;
    cin>>ans;
    rep(i,n-1){
        int a; cin>>a;
        ans=gcd(ans,a);
    }
    cout<<ans<<endl;
}