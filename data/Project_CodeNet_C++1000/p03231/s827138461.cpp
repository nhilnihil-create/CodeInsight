#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

int main(){
  long long N,M;
  string S,T;
  cin >>N>>M;
  cin>>S;
  cin>>T;
  long long L=N*M/gcd(N,M);
  
  long long p=L/N;
  long long q=L/M;
  long long r=p*q/gcd(p,q);
  for (long long i=0;i<L;i=i+r){
      if(!(S.at(i/p)==T.at(i/q))){    
      cout<<-1<<endl;
      return 0;
      }
  }
  cout<<setprecision(20)<<L<<endl;
  return 0;
}

  
  