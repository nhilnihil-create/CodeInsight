#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MOD 1000000007
#define INF 1000000000

int main(){
  string S;
  cin>>S;
  if(S.size()==2){
    cout<<S<<endl;
  }else{
    reverse(S.begin(),S.end());
    cout<<S<<endl;
  }
}
