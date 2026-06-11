#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
#define int long long
using namespace std;
typedef pair<int,int>P;
#define fi first
#define se second

signed main(){
  string s;
  cin>>s;
  int a=0,b=0;
  r(i,s.size()){
    if(s[i]=='0')a++;
    else b++;
  }
  int c=min(a,b);
  a-=c;
  b-=c;
  cout<<c*2<<endl;
}
