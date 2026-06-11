//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
using namespace std;
const int INF= 1e9+5;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>>vvi;

int main(){
  int n,a,b;
  cin>>n>>a>>b;
  int sum=0;
  for(int i=1;i<=n;i++){
    string s=to_string(i);
    int part=0;
    for(int j=0;j<s.size();j++){
      part+=s[j]-'0';
    }
    if(part>=a && part <=b)sum+=i;
  }
  cout<<sum<<endl;
}
    
