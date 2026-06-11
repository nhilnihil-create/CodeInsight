#include<iostream>
using namespace std;
long int gcd(long int a,long int b){
  while(b){
    a=a%b;
    swap(a,b);
  }
  return a;
}

int main(){
  int t; cin >> t;
  for(int i;i<t;i++){
    long int a,b,c,d; cin >> a >> b >> c >> d;
    int ans;
    if(a<b || d<b) ans=0;
    else{
    long int g;
    int f;
      g=gcd(b,d);
      f=(a%g > c%g)?1:0;
      a/=g;
      b/=g;
      c/=g;
      d/=g;
      c-=f;
      ans=(b <= c+1)?1:0;
    }
    cout << (ans?"Yes\n":"No\n");
  }
}
