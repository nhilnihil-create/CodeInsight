#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define INF 1000000000000000000
#define MOD 1000000007
#define MAX 3000000
using Graph=vector<vector<int>>;

int main(){
  int N,Z,W;
  cin>>N>>Z>>W;
  vector<int> a(N);
  for(int i=0;i<N;i++){
    cin>>a.at(i);
  }

  vector<vector<int>> dp(N,vector<int>(N));
  for(int i=0;i<N-1;i++){
    dp.at(i).at(N-1)=abs(a.at(i)-a.at(N-1));
  }
  for(int j=0;j<N-1;j++){
    dp.at(N-1).at(j)=abs(a.at(N-1)-a.at(j));
  }

  if(N==1){
    cout<<abs(W-a.at(N-1))<<endl;
  }else{
    cout<<max(abs(W-a.at(N-1)),abs(a.at(N-1)-a.at(N-2)))<<endl;
  }
}
