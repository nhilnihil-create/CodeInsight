#include <bits/stdc++.h>
using namespace std;


int main() {

  int64_t n;
  cin>>n;

  string s;
  cin>>s;

  int cnt_r=0,cnt_b=0;
  for(int i=0;i<n;i++){
    if(s.at(i)=='R')
      cnt_r++;
    else
      cnt_b++;
  }

  if(cnt_r>cnt_b)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;

  return 0;
}
