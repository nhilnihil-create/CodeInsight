#include <bits/stdc++.h>
using namespace std;
 
long long gcd(long x,long y){
    if(y==0)return x;

    return gcd(y,x%y);
}
long long lcm(long x,long y){
    return x*y/gcd(x,y);
}

int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

int main()
{
    int N,K,A[200010]={},b[200010]={},c=0;
    cin>>N>>K;

    for(int i=0;i<N;i++){
        cin>>A[i];
        if(b[A[i]]==0)c++;
        b[A[i]]++;
    }

    sort(b,b+200010,greater<int>());

    int sum=0;
    int x=0;

    while(1){
        x++;
        if(x>=K){
            sum+=b[x];
        }

        if(b[x]==0)break;
    }

    cout<<sum<<endl;

    return 0;
}