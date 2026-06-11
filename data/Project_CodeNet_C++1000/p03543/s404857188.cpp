#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  string S;
  cin>>S;
  if(S[0]==S[1]&&S[1]==S[2]) {
cout<<"Yes"<<endl;
  }
  else if(S[1]==S[2]&&S[2]==S[3]) {
cout<<"Yes"<<endl;
  }
  else {
cout<<"No"<<endl;
  }
}