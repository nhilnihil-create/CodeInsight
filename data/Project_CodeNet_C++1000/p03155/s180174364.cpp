#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    int N,H,W;
    cin>>N>>H>>W;
    if(N*N<=H*W){cout<<1<<endl;}
    else {cout<<(N-H+1)*(N-W+1)<<endl;}

    return 0;
}