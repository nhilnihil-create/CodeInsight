#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main() {
  int N,a=0,b=0;
  string s;
  cin>>N>>s;
  for(int i=0;i<N;i++){
    if(s[i]=='R') a++;
    else b++;
  }
  if(a>b) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
