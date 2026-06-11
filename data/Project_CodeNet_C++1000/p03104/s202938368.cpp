#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;

vector<pair<int64_t,int64_t>>prime_factorize(int64_t x){
  vector<pair<int64_t,int64_t>>p;
  for(int64_t i=2;i*i<=x;i++){
    int cnt=0;
    if(x%i==0){
    while(x%i==0){cnt++;x/=i;}
    p.push_back(make_pair(i,cnt));
    }
  }
  if(x!=1){p.push_back(make_pair(x,1));}
  return p; 
}

int64_t f(int64_t x){
  if(x==0){return 0;}
  if((x+1)%2!=0){if((x+1)/2%2!=0){return x^1;}
                 else{return 0^x;}
  }
  else{if((x+1)/2%2!=0){return 1;}
       else{return 0;}
  }
}

int main() {
  int64_t A,B;
  cin>>A>>B;
  int64_t a=f(B)^f(A-1);
  cout<<a<<endl;
  return 0;
}