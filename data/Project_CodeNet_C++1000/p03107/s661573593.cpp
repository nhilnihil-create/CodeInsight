#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  int N=s.size();
  int zero=0,one=0;
  for(int i=0;i<N;i++){
    if(s.at(i)=='0')
      zero++;
    else
      one++;
  }
  int ans=N-abs(zero-one);
  cout<<ans<<endl;
}
