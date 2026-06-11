#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
  if(a%b==0)return b;
  return gcd(b,a%b);
}
int main(){
    int N;
    cin>>N;
    cout<<2*N/gcd(2,N)<<endl;
}