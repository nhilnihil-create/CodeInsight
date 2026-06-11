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
    int n; cin>>n;
    cout<<n*(n-1)/2-n/2<<endl;
    if(n%2){
        for(int i=1;i<=n-2;i++){
            for(int j=i+1;j<=n-1;j++){
                if(i+j!=n) cout<<i<<" "<<j<<endl;
            }
        }
        for(int i=1;i<=n-1;i++)
        cout<<i<<" "<<n<<endl;
    }
    else{
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n;j++){
                if(i+j!=n+1) cout<<i<<" "<<j<<endl;
            }
        }
    }
}