#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll N;
    cin>>N;
    long long b[N];
    long long mb=0;
    long long ma=0;
    for(long long i=0;i<N;i++){
    cin>>mb;
    while(mb%2==0){
    ma++;
    mb/=2;}}
    cout<<ma<<endl;}
