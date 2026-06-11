#include<iostream>
#include<vector>
using namespace std;
typedef long long li;
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }

li init(li n){
  li f=n<0,b=1;
  if(f){
    n*=-1; b=2;
  }
  li s=b;
  while(s<n){
    b*=4;
    s+=b;
    if(df)print(s);
  }
  return b*(f?-1:1);
}

int main(){
  li n; cin >>n;
  vector<li> v;
  if(n==0){ print(0); return 0; }
  while(n){
    li c=init(n);
    if(df)print(c);
    v.push_back(c);
    n-=c;
  }
  
  li b=v[0],i=0;
  while(b){
    if(b==v[i]){
      printf("1");
      i++;
    }else{
      printf("0");
    }
    b/=-2;
  }
  printf("\n");
}
