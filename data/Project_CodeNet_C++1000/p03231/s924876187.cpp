#include<iostream>
using namespace std;
long long gcd(long long x,long long y){return y?gcd(y,x%y):x;}
long long lcm(long long x,long long y){return x*y/gcd(x,y);}
long long N,M;
string S,T;
int main(){
    cin>>N>>M>>S>>T;
    long long L=lcm(N,M),n=N/gcd(N,M),m=M/gcd(N,M);
    for(int i=0;i<gcd(N,M);i++)if(S[n*i]!=T[m*i]){cout<<-1<<endl;return 0;}
    cout<<L<<endl;
    return 0;
}