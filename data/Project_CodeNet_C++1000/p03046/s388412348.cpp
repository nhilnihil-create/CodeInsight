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
    int m,k; cin>>m>>k;
    if(k>=(1<<m)) cout<<-1<<endl;
    else if(m==0){
        cout<<"0 0"<<endl;
    }
    else if(m==1){
        if(k==0) cout<<"0 0 1 1"<<endl;
        else cout<<-1<<endl;
    }
    else{
        for(int i=0;i<(1<<m);i++) if(i!=k) cout<<i<<" ";
        cout<<k<<" ";
        for(int i=(1<<m)-1;i>=0;i--) if(i!=k) cout<<i<<" ";
        cout<<k<<endl;
    }
}