#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<pair<int,int>>>;
using pp=pair<int,pair<int,int>>;
#define MOD 1000000007
#define INF 1000000000

int main(){
  int N;
  string S;
  cin>>N>>S;
  int r=0;
  int b=0;
  for(int i=0;i<N;i++){
    if(S.at(i)=='R'){
      r++;
    }else{
      b++;
    }
  }

  if(r>b){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}
