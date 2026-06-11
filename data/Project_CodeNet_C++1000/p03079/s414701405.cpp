#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  vector<int> t(3);
  cin>>t[0]>>t[1]>>t[2];
  sort(t.begin(), t.end());
  cout<<( (t[2]==t[0]) ? "Yes" : "No" )<<endl;
  return 0;
}