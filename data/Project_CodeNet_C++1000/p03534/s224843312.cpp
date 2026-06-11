#include <bits/stdc++.h>
using namespace std;

signed main(){
  string s;
  cin>>s;
  int N=s.size();
  int a,b,c;
  a=b=c=0;
  for(int i=0;i<N;i++){
    if(s[i]=='a')a++;
    if(s[i]=='b')b++;
    if(s[i]=='c')c++;
  }
  int out=0;
  if(a>((N-1)/3)+1)out++;
  if(b>((N-1)/3)+1)out++;
  if(c>((N-1)/3)+1)out++;
  if(out)cout<<"NO"<<endl;
  else cout<<"YES"<<endl;
}
