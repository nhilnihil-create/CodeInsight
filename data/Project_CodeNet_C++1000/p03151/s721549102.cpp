#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using vin=vector<int>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;

int main() {
  int n;
  cin>>n;
  vin a(n),b(n);
  rep(i,n) cin>>a[i];
  rep(i,n) cin>>b[i];
  ////////総和　少ない数をカウント
  ll aSum=0,bSum=0;
  bool ok=true;
  rep(i,n){
   aSum+=a[i];
   bSum+=b[i];
    
  }
  if(aSum<bSum) ok=false;
  ll cnt=0;
  ll husoku=0;
  priority_queue<int, vector<int>, less<int>> q;
  rep(i,n){
   if(a[i]<b[i]){
    cnt++; 
     husoku+=(b[i]-a[i]);
   }
   else{
    q.push(a[i]-b[i]);
    
   }
  }
  if(ok){
  while(husoku>0){
   cnt++; 
    husoku-=q.top();
    q.pop();
    
  }
  }
  
  if(ok) cout<<cnt<<endl;
  else cout<<-1<<endl;
}