#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define all(x) (x).begin(),(x).end()
using ll = long long;
using namespace std;

int main() {
 int a,b,c;
  cin>>a>>b>>c;
  ///////
  int ans=0;
  int mx=max(a,max(b,c));
  int mn=min(a,min(b,c));
  int md=a+b+c-mn-mx;
  /////////
  ans+=mx-md;
  mn+=ans;
  if(mn%2==mx%2){
    ans+=(mx-mn)/2;
  }
  else{
   ans+=(mx-mn+1)/2 +1;
  }
  cout<<ans<<endl;
}