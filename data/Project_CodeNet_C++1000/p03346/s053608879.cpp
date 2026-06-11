#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MAX 1000000
#define MOD 1000000007
#define INF 1000000000

int main(){
  int N;
  cin>>N;
  vector<int> P(N);
  for(int i=0;i<N;i++){
    cin>>P.at(i);
  }

  vector<int> length(N+1,0);
  for(int i=0;i<N;i++){
    length.at(P.at(i))=length.at(P.at(i)-1)+1;
  }
  int ans=0;
  for(int i=0;i<N+1;i++){
    ans=max(ans,length.at(i));
  }
  cout<<N-ans<<endl;
}
