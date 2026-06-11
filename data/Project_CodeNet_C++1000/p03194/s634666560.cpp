#include<iostream>
#include<cmath>
using namespace std;
int main(){
    long long  n,p;
    cin >> n >> p;
    long long ans=1;
    for(long long i=2;i<=pow((long double)p,(long double)1/n);i++){
      if(n==1) {
        ans=p;
        break;
      }
        if(p%(long long)pow((long double)i,(long double)n)==0) ans=i;
    }
    cout << ans <<endl;
}