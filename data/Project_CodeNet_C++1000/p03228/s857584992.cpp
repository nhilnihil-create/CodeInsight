#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
//#define int long long
int abs(int a,int b){
  int c=max(a,b)-min(a,b);
  return c;
}
priority_queue<int, vector<int>, greater<int> > qu;
signed main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int a,b,c;
  int d=0,e=0;
  cin>>a>>b>>c;
  for(int i=0;i<c;i++){
    if(i%2==0){
      if(a%2==1) a--;
      a/=2;
      b+=a;
    }
    else{
      if(b%2==1) b--;
      b/=2;
      a+=b;
    }
  }
  cout<<a<<" "<<b<<"\n";
}