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
  int N; cin>>N;
  int left=0,right=N;
  cout<<left<<endl;
  string L; cin>>L;
  rep(i,1,20){
    int mid=(left+right)/2;
    cout<<mid<<endl;
    string S; cin>>S;
    if(S=="Vacant") break;
    else if((mid-left)%2==0){
      if(L==S){
        left=mid;
        L=S;
      }
      else{
        right=mid;
      }
    }
    else{
      if(L==S){
        right=mid;
      }
      else{
        left=mid;
        L=S;
      }
    }
  }
  }
