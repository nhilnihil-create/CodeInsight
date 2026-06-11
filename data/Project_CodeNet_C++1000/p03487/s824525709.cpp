#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)
typedef pair<int, int> p;


int main(){
  ll n;
  cin>>n;
  vector<ll>a(n,0);
  rep(i, n)cin >>a.at(i);
  sort(a.begin(),a.end());
  ll ans = 0, a1=0, a2=1,begin,end;
  if(n==1){
    if(a.at(0)!=1)cout<<1;
    else cout<<0;
  }
  
  else{
  while(a2<n){
    begin =a.at(a1), end=a.at(a2);
    if(end>begin){
        //cout<<a2-1<<" " << a1<<endl;
      if(a2-a1>begin){
      
        ans+=(a2-a1)-begin;
      }
      else if(a2-a1<begin){
        ans+=a2-a1;
      }
      a1=a2;
      a2+=1;  
      //cout<<"ans"<<ans<<endl;;
    }
    else{
      a2++;
    }
    
  }
  //cout << a1<<" "<< a2<<" "<<begin<<endl;

  if(a2-a1>begin){
    ans+=(a2-a1)-begin;
  }
  else if(a2-a1<begin){ans+=a2-a1;}
  cout<<ans;
}
}
