#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pp=pair<ll,pair<int,int>>;
using Graph=vector<vector<pair<int,ll>>>;

int main(){
  int N;
  cin>>N;
  vector<int> A(N);
  map<int,int> m;
  for(int i=0;i<N;i++){
    cin>>A.at(i);
    m[A.at(i)]++;
  }
  sort(A.begin(),A.end());
  reverse(A.begin(),A.end());

  int ans=0;
  for(int i=0;i<N;i++){
    if(m[A.at(i)]>0){
      int n=1;
      while(n<=A.at(i)){
        n<<=1;
      }
      if(m[n-A.at(i)]>0&&A.at(i)!=n-A.at(i)){
        ans++;
        m[A.at(i)]--;
        m[n-A.at(i)]--;
      }else if(m[n-A.at(i)]>=2){
        ans++;
        m[A.at(i)]-=2;
      }
    }
  }

  cout<<ans<<endl;
}
