#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1001001001001001;



int main() {
  ll n;
  cin>>n;
  vector<ll> a(n);
  vector<ll> b(n);

  rep(i,n){
    cin>>a[i];
  }
  ll now=a[0];
  ll id=1;
  ll ans=n;
//  cout<<(now&a[id])<<endl;
  rep(i,n){

    if (id<=i){
      id=i+1;
      now=a[i];
    }

     while(id<n){
       /*
       if (id==n-1){
        // cout<<(now&a[id])<<' '<<i<<' '<<id<<endl;
         b[i]=id;
         if ((now&a[id])==0) {
           ans+=id-i;
           now-=a[i];
           cout<<id-i<<endl;
         }

         break;
       }
       */
       if ((now&a[id])!=0){
      //   cout<<'l'<<' '<<(now&a[id])<<' '<<i<<' '<<id<<endl;
         b[i]=id;
         now-=a[i];
         //cout<<id-i-1<<endl;

         break;
       }
        if ((now&a[id])==0){
      //    cout<<'k'<<' '<<(now&a[id])<<' '<<i<<' '<<id<<' '<<now<<endl;
          now=now|a[id];
          ans+=id-i;
          id++;
        //  cout<<now<<'n'<<endl;
        }


     }
  }

cout<<ans;

}
