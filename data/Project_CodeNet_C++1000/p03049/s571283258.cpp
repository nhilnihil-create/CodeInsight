#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 998244353
#define MAX 100
#define INF 800000000

int main(){
  int N;
  cin>>N;
  vector<string> s(N);
  for(int i=0;i<N;i++){
    cin>>s.at(i);
  }
  int ans=0;
  int A=0;
  int B=0;
  int same=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<s.at(i).size()-1;j++){
      if(s.at(i).at(j)=='A'&&s.at(i).at(j+1)=='B'){
        ans++;
      }
    }
    if(s.at(i).at(0)=='B'){
      B++;
    }
    if(s.at(i).at(s.at(i).size()-1)=='A'){
      A++;
    }
    if(s.at(i).at(0)=='B'&&s.at(i).at(s.at(i).size()-1)=='A'){
      same++;
    }
  }
  if(A==same&B==same){
    cout<<ans+max(same-1,0)<<endl;
  }else{
    cout<<ans+min(A,B)<<endl;
  }
}
