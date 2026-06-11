#include<bits/stdc++.h>
using namespace std;
const int N=2020;
bitset<N*N>b;
int n,S;
int main(){
    scanf("%d",&n);b.set(0);
    for(int i=1,x;i<=n;i++)
        scanf("%d",&x),b|=b<<x,S+=x;
    for(int i=(S+1)/2;;i++)if(b[i])cout<<i,exit(0);
    return 0;
}