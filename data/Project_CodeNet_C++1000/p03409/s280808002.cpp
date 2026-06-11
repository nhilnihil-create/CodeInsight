#include<bits/stdc++.h>
#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef long  l;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<n;i++)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
const int INF=1000000001;
const double PI=3.141592653589;


int main(){
  int n; cin>>n;
  vector<P> r(n);
  vector<P> b(n);
  rep(i,n) cin>>r[i].sc>>r[i].fs;
  rep(i,n) cin>>b[i].fs>>b[i].sc;

  sort(ALL(b));
  sort(ALL(r),greater<P>());

  // cout<<"r"<<endl;
  // rep(i,n){
  //   cout<<r[i].fs<<" "<<r[i].sc<<endl;
  // }
  // cout<<"b"<<endl;
  // rep(i,n){
  //   cout<<b[i].fs<<" "<<b[i].sc<<endl;
  // }
  int ans=0;
  vector<bool> memo(n,0);
  // cout<<"ikuyo-"<<endl;
  rep(i,n){
    rep(j,n){
      if(memo[j]) continue;
      if((r[j].sc<b[i].fs)&&(r[j].fs<b[i].sc)){
        ans++;
        memo[j]=1;
        break;
        // cout<<r[j].fs<<" "<<r[j].sc<<endl<<"b"<<endl;
        // cout<<b[i].fs<<" "<<b[i].sc<<endl;
      }
    }
  }
  cout<<ans<<endl;
  return 0;

}
