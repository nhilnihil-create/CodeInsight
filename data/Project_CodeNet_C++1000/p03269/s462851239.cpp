#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define MOD 1000000007
#define int long long
#define ALL(a) (a).begin(),(a).end()
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define priq priority_queue<int>
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(int)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(int)(key)))
#define tii tuple<int,int,int>
#define Priq priority_queue<int,vi,greater<int>>
#define pb push_back
#define mp make_pair
#define INF (1ll<<60)
signed main(){
  int L; cin>>L;
  bitset<20> B(L);
  int memo;
  REP(i,1,20){
    if(B.test(20-i)){
      memo=20-i;
      break;
    }
  }
  cout<<memo+1<<" "<<2*memo+B.count()-1<<endl;
  rep(i,0,memo){
    cout<<i+1<<" "<<i+2<<" "<<0<<endl;
    cout<<i+1<<" "<<i+2<<" "<<(1ll<<i)<<endl;
  }
  int sum=(1ll<<memo);
  rep(i,0,memo){
    if(B.test(i)){
      cout<<i+1<<" "<<memo+1<<" "<<sum<<endl;
      sum+=(1ll<<i);
    }
  }
  }

