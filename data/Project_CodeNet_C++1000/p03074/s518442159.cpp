#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
 
int main() {
  int n,k;
  string s;
  cin>>n>>k>>s;
  vector<int>a;
  vector<int>b;
  a.push_back(-1);
  if(s.at(0)=='0'){
    b.push_back(-1);
  }
  rep(i,n-1){
    if(s.at(i)=='0'&&s.at(i+1)=='1'){
      a.push_back(i);
    }
    if(s.at(i)=='1'&&s.at(i+1)=='0'){
      b.push_back(i);
    }
  }
  b.push_back(n-1);
  int si=b.size();
  if(si<=k){
    cout<<n<<endl;
  }
  else{
    int ma=0;
    rep(i,si-k){
      ma=max(ma,b.at(i+k)-a.at(i));
    }
    cout<<ma<<endl;
  }
}