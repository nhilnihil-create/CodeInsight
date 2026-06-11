#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    int a, b, k;
    cin>>a>>b>>k;
    if(b-a>=2*k){
        rep(i, k) cout<<a+i<<endl;
        rep(i, k) cout<<b-(k-1)+i<<endl;
    }
    else {
        for(int i =a;i<=b;i++) cout<<i<<endl;
    }
    return 0;
}