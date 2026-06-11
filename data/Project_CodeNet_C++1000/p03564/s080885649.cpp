#include <bits/stdc++.h>
#define pb push_back
#define Int long long
using namespace std;

const int MAXN=50005;
const int NAX=1005;
const long MOD=(long)(1e9+7);

Int N,M,K;
Int X,Y,Z;

int main()
{
    int start=1;
    cin>>N>>K;
    int times=N;
    while(times--){
        if(start<K) start*=2;
        else start+=K;
    }
    cout<<start<<"\n";
   
}
