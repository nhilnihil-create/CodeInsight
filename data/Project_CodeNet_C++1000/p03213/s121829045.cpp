#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<bool>a(101,true);
  
  a.at(0)==false;
  a.at(1)==false;
  
  
  rep2(i,2,n+1){
    if(a.at(i)){
      for(int j=i*2;j<n+1;j+=i){
        a.at(j)=false;
      }
    }
  }
  vector<int>b(101);
  rep2(i,2,n+1){
    if(a.at(i)){
      int ch=n/i;
      while(ch>0){
        b.at(i)+=ch;
        ch/=i;
      }
    }
  }
  int c=0;
  int d=0;
  int e=0;
  int f=0;
  int g=0;
  rep(i,n+1){
    if(b.at(i)>=74){
      c++;
    }
    if(b.at(i)>=24){
      d++;
    }
    if(b.at(i)>=14){
      e++;
    }
    if(b.at(i)>=4){
      f++;
    }
    if(b.at(i)>=2){
      g++;
    }
  }
  int h=0;
  if(g>1){
    h=d*(g-1);
  }
  int m=0;
  if(f>1){
    m=e*(f-1);
  }
  int l=0;
  if(f>1&&g>2){
    l=f*(f-1)/2*(g-2);
  }
  
  int ans=c+h+m+l;
  cout<<ans<<endl;

  
}
  


