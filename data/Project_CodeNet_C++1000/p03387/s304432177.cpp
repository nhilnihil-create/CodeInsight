#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
   ll a,b,c;cin >>a>>b>>c;
   ll ans=INF;
    for (int i = 0; i <=100; ++i) {
        ll now=0;
        if(a<i){
          ll d=i-a;
          if(d%2==1){
              now+=d/2+2;
          }
          else now+=d/2;
        }
        else {
            now+=a-i;
        }
        if(b<i){
            ll d=i-b;
            if(d%2==1){
                now+=d/2+2;
            }
            else now+=d/2;
        }
        else {
            now+=b-i;
        }
        if(c<i){
            ll d=i-c;
            if(d%2==1){
                now+=d/2+2;
            }
            else now+=d/2;
        }
        else {
            now+=c-i;
        }
//        cout <<i <<" "<<now<<endl;
        ans=min(ans,now);
    }
    cout <<ans <<endl;
   return 0;
}