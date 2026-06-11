#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define all(x) (x).begin(),(x).end()
using ll = long long;
using namespace std;

int main() {
  ll a,b,k;
  cin>>k>>a>>b;
  ll   ans;
  if(a+3>b){
    ans=1+k;
  }
  else {
  ll mtk=a;
    if(k>=a+1){
  ll nkr;
     mtk=b;
    nkr=k-(a+1);
    ll c=nkr/2;
    mtk=b+(b-a)*c;//1¥
    if(nkr%2==0){}
      else mtk++;
   ans=mtk;
    }
    else{
      ans=1+k;
    }
  }
  
    
  
  cout<<ans<<endl;
}