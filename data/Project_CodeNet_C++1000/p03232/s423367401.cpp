#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=100010,Mo=1000000007;
int inv[N];
inline int gi() {
    int x=0,o=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=='-'?o=-1:0,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return o*x;
}
int main() {
    int n,sum=1,ans=0;
    cin>>n;
    inv[1]=1;
    for(int i=2;i<=n;i++)
	inv[i]=-1LL*Mo/i*inv[Mo%i]%Mo,sum=(sum+inv[i])%Mo;
    for(int i=1;i<=n;i++) {
	ans=(ans+1LL*sum*gi())%Mo;
	sum=(1LL*sum-inv[n-i+1]+inv[i+1])%Mo;
    }
    for(int i=1;i<=n;i++) ans=1LL*ans*i%Mo;
    cout<<(ans+Mo)%Mo;
    return 0;
}