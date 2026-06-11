#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main() {
  int n;
  cin >> n;
  vector<int>x(n),y(n),h(n);
  rep(i,n){
    cin>>x.at(i)>>y.at(i)>>h.at(i);
  }
  if(n==1){
    cout<<x.at(0)<<" "<<y.at(0)<<" "<<h.at(0)<<endl;
  }
  else{
  int a,b,c;
  
  rep(i,101){
    rep(j,101){
      bool ch=true;
      int now=-1;
      rep(k,n){
        if(h.at(k)!=0){
          if(now==-1){
            now=abs(x.at(k)-i)+abs(y.at(k)-j)+h.at(k);
          }
          else{
            if(now!=abs(x.at(k)-i)+abs(y.at(k)-j)+h.at(k)){
              ch=false;
            }
          }
        }      
      }
      rep(k,n){
        if(h.at(k)==0){
          if(now-abs(x.at(k)-i)-abs(y.at(k)-j)>0){
            ch=false;
          }
        }
      }
      if(ch){
        a=i;
        b=j;
        c=now;
      }
    }
  }
  
  cout<<a<<" "<<b<<" "<<c<<endl;
  }
  
}

