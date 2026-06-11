#include<bits/stdc++.h>
using namespace std;

int main(){
  long long int N,P;

  long long int pans = 0,ans = 0;

  cin >>N>>P;

  if(N == 1){
    cout <<P<<endl;
    return 0;
  }

  while(pow(pans,N) <= P ){
    pans++;
    /*cout <<pans<<endl;
    cout <<pow(pans,N)<<' '<<P<<endl;
    cout <<(double)P/pow(pans,N)<<' '<<(long long int)(P/pow(pans,N))<<endl;
    /*if (pans == 210)break;*/
    if((P % (long long int)pow(pans,N)) == 0)ans = pans;
  }

  cout <<ans<<endl;
  return 0;
}
