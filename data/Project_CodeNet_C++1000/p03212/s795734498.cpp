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
    int n,c=1,ans=0; cin>>n;
    for(int i=1;i<10;i++){
        c*=3;
        rep(j,c){
            int q=j,num=0,d=1;
            int a3=0,a5=0,a7=0;
            rep(k,i){
                int f=2*(q%3)+3;
                q/=3;
                if(f==3) a3=1;
                if(f==5) a5=1;
                if(f==7) a7=1;
                num+=d*f;
                d*=10;
            }
            if(a3*a5*a7!=0 && n>=num) ans++;
        }
    }
    cout<<ans<<endl;
}
