#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  
  map<string,int> m;
  
  string s;
  char c;
  rep(i,n){
    cin>>s;
    if(m[s]!=0){
      cout<<"No"<<endl;
      return 0;
    }
    if(i!=0 && s[0]!=c){
      cout<<"No"<<endl;
      return 0;
    }
    m[s]++;
    c=s[s.size()-1];
  }
  cout<<"Yes"<<endl;

  return 0;
}