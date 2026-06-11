#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main() {
  long n,x;
  cin >>n>>x;
  
  vector<int>a(n),b(n);
  rep(i,n){
    cin>>a.at(i)>>b.at(i);
  }
  int ans=1001001001;
  for (int tmp = 0; tmp < (1 << n); tmp++) {
    bitset<10> s(tmp);
    int now=0;
    int ch=-1;
    int co=0;
    rep(i,n){
      if(s.test(i)){
        now+=(i+1)*100*a.at(i)+b.at(i);
        co+=a.at(i);
      }
      else{
        ch=i;
      }
    }   
    if(now<x&&x-now<100*(ch+1)*a.at(ch)){
      co+=((x-now)/100-1)/(ch+1)+1;
      ans=min(ans,co);
    }
    else if(now>=x){
      ans=min(ans,co);
    }
  }  
  cout<<ans<<endl;  
}