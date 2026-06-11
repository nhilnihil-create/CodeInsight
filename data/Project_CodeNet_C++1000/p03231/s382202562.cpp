#include <iostream>
#include <string>
using namespace std;

long long gcd(long long a, long long b){
  if( (a%b==0) ){
    return b;
  }else{
    return gcd(b,a%b);
  }
}
    

int main(){
  long long N,M;
  string S,T;
  string subS="",subT="";
  long long g,l;
  cin >> N >> M >> S >> T;
  g=gcd(N,M);
  l=N*M/g;
  for(auto itr=S.begin();itr<S.end();itr+=N/g)
    subS+=*itr;
  for(auto itr=T.begin();itr<T.end();itr+=M/g)
    subT+=*itr;
  while( (!subS.empty()) || (!subT.empty()) ){
    if( subS[0]!=subT[0] ){
      l=-1;
      break;
    }else{
      subS.erase(0,1);
      subT.erase(0,1);
    }
  }
  cout << l << endl;
}