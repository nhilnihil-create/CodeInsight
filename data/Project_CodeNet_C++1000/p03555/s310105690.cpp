#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    string s,s1;
    cin>>s>>s1;

    bool ok=false;
  reverse(s.begin(),s.end());

  if(s==s1)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}
