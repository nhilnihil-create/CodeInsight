#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;

ll big[100010];

int main(){
    ll N;cin>>N;
    ll a[100010],b[100010];
    rep(i,0,N)cin>>a[i];
    rep(i,0,N)cin>>b[i];
    ll cn=0,cn2=0;
    rep(i,0,N){
        if(a[i]>b[i]){
            big[i]=1;
            cn+=a[i]-b[i];
        }
        else{
            cn2+=(b[i]-a[i])/2;
        }
    }
    if(cn2>=cn)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}





