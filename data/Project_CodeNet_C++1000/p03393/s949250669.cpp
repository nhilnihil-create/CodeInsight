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
  string S; cin>>S;
  int N=S.size();
  if(N==26){
    if(S=="zyxwvutsrqponmlkjihgfedcba") S="-1";
    else{
      REP(o,2,N){
        int i=N-o;
        int memo=-1;
        char X;
        rep(j,i+1,N){
          if(S[i]<S[j]){
            if(memo==-1||X>S[j]){
              memo=j;
              X=S[j];
            }
          }
        }
        if(memo!=-1){
          swap(S[i],S[memo]);
          S=S.substr(0,i+1);
          break;
        }
      }
    }
  }
  else{
    vector<bool> F(26,1);
    rep(i,0,N) F[S[i]-'a']=0;
    rep(i,0,26){
      if(F[i]){
        S+=i+'a';
        break;
      }
    }
  }
  cout<<S<<endl;
  }
