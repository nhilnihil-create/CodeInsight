#include <bits/stdc++.h>
using namespace std;
const int N=100050;
int v[N],n,s;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int main(){
    cin>>n;
    for (int i=2; i<=30000; ++i)
	if (i%2==0||i%3==0){
	    v[i]=1,s+=i,--n;
	    if (n==1) break;
	}
    for (int i=2; i<=30000; ++i)
	if (!v[i]&&(s+i)%2==0&&(s+i)%3==0&&gcd(s,i)!=1)
	    { v[i]=1; break; }
    for (int i=2; i<=30000; ++i)
	if (v[i])
	    printf("%d ",i);
    return 0;
}
