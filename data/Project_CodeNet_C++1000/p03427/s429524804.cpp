#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N;
  cin>>N;
  cout<<(to_string(N).size()-1LL)*9+(N+1)/(int)pow(10LL,to_string(N).size()-1LL)-1<<endl;
}