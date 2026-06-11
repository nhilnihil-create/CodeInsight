#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
#define rep(i,j,n) for (ll i = j; i < (n); i++)
#define CLR(mat,f) memset(mat, f, sizeof(mat))
#define IN(a, b, x) (a<=x&&x<b)
#define out(ans) cout << ans << endl
typedef pair<ll,ll>P;
const ll mod=1e9+7;
const int INF = 1000000;
const double PI=3.14159265359;


int main(){

  bool num[10];CLR(num,false);

  rep(i,0,4){
    int a;cin>>a;
    // a--;
    num[a]=true;
  }
  ll count=0;
  rep(i,0,10){
    if(num[i]&&(i==1||i==4||i==7||i==9))count++;
  }

  if(count==4)out("YES");
  else out("NO");



  return 0;
}

// #include "bits/stdc++.h"

// using namespace std;
// typedef long long ll;
// #define rep(i,j,n) for (ll i = j; i < (n); i++)
// #define CLR(mat,f) memset(mat, f, sizeof(mat))
// #define IN(a, b, x) (a<=x&&x<b)
// #define out(ans) cout << ans << endl
// typedef pair<ll,ll>P;
// const ll mod=1e9+7;
// const int INF = 1000000;
// const double PI=3.14159265359;

// ll n;
// ll a[10][10];
// ll v[10];
// ll ma=0;
// ll sum=0;

// void dfs(int num){
//   // out(1234);
//   if(num==n){
//     // out(num);
//     // vector<int>aa,b,c;
//     // rep(i,0,n){
//     //   if(v[i]==0){
//     //     aa.push_back(i);
//     //   }else if(v[i]==1){
//     //     b.push_back(i);
//     //   }else if(v[i]==2){
//     //     c.push_back(i);
//     //   }
//     // }
//     // ll sum=0;
//     // rep(i,0,aa.size()-1){
//     //   rep(j,i+1,aa.size()){
//     //     sum+=a[aa[i]][aa[j]];
//     //   }
//     // }
//     // rep(i,0,b.size()-1){
//     //   rep(j,i+1,b.size()){
//     //     sum+=a[b[i]][b[j]];
//     //   }
//     // }
//     // rep(i,0,c.size()-1){
//     //   rep(j,i+1,c.size()){
//     //     sum+=a[c[i]][c[j]];
//     //   }
//     // }

//     ma=max(ma,sum);

//   }else{
//     // rep(i,0,1){
//       v[num]=0;
//       dfs(num+1);
//     // }
//   }

// }

// int main(){

//   // int b=10;
//   int a,b,c;
//   a=b=c=10;

//   rep(i,0,10){
//     cout<<a<<":"<<b<<":"<<c<<endl;
//     // out(b--);

//     // out(--b);
//   }

//   // cin>>n;
//   // rep(i,0,n-1){
//   //   rep(j,i+1,n){
//   //     cin>>a[i][i+j];
//   //     sum+=a[i][i+j];
//   //   }
//   // }
//   // dfs(0);
// //
//   // out(ma);

//   return 0;
// }
