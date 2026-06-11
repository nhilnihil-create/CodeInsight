#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define adrep(i,s,n) for (int i=(s);i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pint;
vector<pint> A;
bool cmp(pint a, pint b) { return a.second < b.second; }

int main(){

 
  int N,M;
  cin>>N>>M;
  A.resize(M);
  rep(i,M){

    cin>>A[i].first>>A[i].second;    

  }
  sort(A.begin(),A.end(),cmp);
  
  int ans=0;
  int endtime=0;
  
  rep(i,M){


    if(A[i].first>=endtime){
    
      endtime=A[i].second;
      ans++;
    }
    
  }

  cout<<ans<<endl;
  
}
