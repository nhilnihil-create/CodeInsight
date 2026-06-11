#include <bits/stdc++.h>
using namespace std;

int64_t gcd(int64_t a,int64_t b){
  while(b!=0){
    int64_t temp=a%b;
    a=b;
    b=temp;
  }
  return a;
}

int64_t lcm(int64_t a,int64_t b){
  return a*b/gcd(a,b);
}

int main(){
  int64_t N,M;
  cin >> N >> M;
  int64_t L=lcm(N,M);
  string S,T;
  cin >> S >> T;
  int64_t a=0;
  int64_t b=0;
  while(1){
    if((a>=N)||(b>=M)){
      break;
    }
    if(a*(L/N)==b*(L/M)){
      if(S.at(a)==T.at(b)){
        a++;
        b++;
      }else{
        cout << -1 << endl;
        return 0;
      }
    }else if(a*(L/N)<b*(L/M)){
      a++;
    }else{
      b++;
    }
  }
  cout << L << endl;
  return 0;
}
