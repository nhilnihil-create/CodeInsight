#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  long n;
  cin >> n;
  long a,b,c;
  rep2(j,n/4+1,n/2+1){  
    long ren=n*j/(4*j-n)+1;
    bool ex=false;
    rep2(i,ren,2*ren+1){
      if(n*j*i%((4*j-n)*i-n*j)==0){
        a=j;
        b=i;
        c=n*j*i/((4*j-n)*i-n*j);
        ex=true;
        break;
      }
    }
    if(ex){
      break;
    }
  }
  cout<<a<<" "<<b<<" "<<c<<endl;  
}