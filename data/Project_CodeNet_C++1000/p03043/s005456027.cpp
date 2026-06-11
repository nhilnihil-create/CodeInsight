#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);++i)
using namespace std;
using ll = long long;
using P= pair<int,int>;
 
int main() {
    ll N,K;
    cin>>N>>K;
    long double rate=0.0;
    for(int i=1;i<=N;i++){
      ll n=i;
      ll t=0;
      
      while(n<K){
        n*=2;
        t++;
        //cout<<n<<endl;
      }
      //cout<<t<<endl;
      long double d=(long double)1.0/(long double)N;
      rate+=d*pow((long double)0.5,(long double)t);
      //cout<< fixed << setprecision(15) <<(1/N)+pow(0.5,t)<<endl;
    }
    
    cout<< fixed << setprecision(15) <<rate<<endl;
    return 0;
}