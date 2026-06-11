#include <bits/stdc++.h>
using namespace std;
//解き方をすっかり忘れていました
int main(){
  int n;
  cin>>n;
  vector<tuple<string,int,int>>a;
  for(int i=0;i<n;i++){
    string s;
    int b;
    cin>>s>>b;
    a.emplace_back( s, -1*b, i+1 );
  }
  sort(a.begin(),a.end());
  
  for(int i=0;i<n;i++){
    cout<<get<2>(a[i])<<endl;
  }
  return 0;
}