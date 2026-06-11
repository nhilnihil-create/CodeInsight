#include <bits/stdc++.h>
#define ll long long
#define INF 9999999999999LL
#define MAXN 2005
using namespace std;
ll n,sum,a;
bitset <MAXN*MAXN> bs;
int main(){
    bs[0]=1;

    cin>>n;
    for (int i=0; i<n; i++){
        cin>>a;
        sum+=a;
        bs|=bs<<a;    
    }

    for (int i=(sum+1)/2; i<=sum; i++)
    if (bs[i]) { cout<<i<<endl; return 0; }
}