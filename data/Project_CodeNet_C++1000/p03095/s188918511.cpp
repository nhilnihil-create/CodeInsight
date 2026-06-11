#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N;
  string S;
  cin>>N>>S;
  vector<int> A(26);
  for(char c:S)
    A[c-'a']++;
  int ans=1;
  for(int i:A)
    ans=ans*(i+1)%1000000007;
  cout<<ans-1<<endl;
}