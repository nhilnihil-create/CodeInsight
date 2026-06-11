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
    int N,A[100010]={},B[100010]={},ans=0,o[100010]={},ocnt=0;
    long long Asum=0,Bsum=0,r=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
        Asum+=A[i];
    }
    for(int i=0;i<N;i++){
        cin>>B[i];
        Bsum+=B[i];

        if(A[i]>=B[i]){
            o[ocnt]=A[i]-B[i];
            ocnt++;
        }else{
            ans++;
            r+=B[i]-A[i];
        }
    }

    if(Bsum>Asum){
        ans=-1;
    }else{

        sort(o,o+ocnt);

        while(r>0){
            ans++;
            r-=o[ocnt-1];
            ocnt--;
        }
    }

    cout<<ans<<endl;

    return 0;
}