#include <bits/stdc++.h>
using namespace std;

int main(){
  string s; cin>>s;
  int ans=700;
  for (char d : s){
    if (d=='o')  ans+=100;
  }
  cout<<ans<<endl;
}