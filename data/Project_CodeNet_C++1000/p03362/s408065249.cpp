#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MAX 1000000
#define MOD 1000000007
#define INF 100000000000000

vector<int> p;
vector<bool> p_table(MAX+1,true);
void prime(){
  p_table.at(0)=false,p_table.at(1)=false;
  for(int i=2;i<=MAX;i++){
    if(p_table.at(i)){
      p.push_back(i);
      for(int j=2;i*j<=MAX;j++){
        p_table.at(i*j)=false;
      }
    }
  }
}

int main(){
  int N;
  cin>>N;
  prime();
  int n=0;
  vector<int> ans;
  for(int i=0;n<N;i++){
    if(p.at(i)%5==2){
      ans.push_back(p.at(i));
      n++;
    }
  }
  for(int i=0;i<N;i++){
    cout<<ans.at(i)<<" ";
  }
  cout<<endl;
}
