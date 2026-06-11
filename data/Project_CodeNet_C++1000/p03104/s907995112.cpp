#include <bits/stdc++.h>
using namespace std;
long long oddsolve(long long a){return (a+1)/2%2;}
long long    solve(long long a){if(a%2==0){ return
          oddsolve(a+1)^(a+1);}
          else return oddsolve(a);}
int main(){
long long a, b;
cin>>a>>b;
cout<<(solve(b)^solve(a-1))<<endl;}
