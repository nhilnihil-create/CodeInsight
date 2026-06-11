#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int c1,c2,c3,c4,c5,c6,c7,c8,c9;
  cin>>c1>>c2>>c3>>c4>>c5>>c6>>c7>>c8>>c9;
  bool ans=1;
  if(c1!=c2+c4-c5)ans=0;
  if(c1!=c3+c7-c9)ans=0;
  if(c5!=c6+c8-c9)ans=0;
  if(ans)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}

