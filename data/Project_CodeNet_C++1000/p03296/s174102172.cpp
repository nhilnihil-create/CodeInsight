#include <bits/stdc++.h>
using namespace std;
 
int gcd(int x,int y){
    if(y==0)return x;

    return gcd(y,x%y);
}
int lcm(int x,int y){
    return x*y/gcd(x,y);
}

int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

int main(){

    int N,a[110]={},ans=0;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>a[i];
    }

    for(int i=2;i<=N-1;i++){
        if(a[i-1]==a[i]
        &&a[i]==a[i+1]){
            a[i]++;
            ans++;
        }
    }

    for(int i=1;i<N;i++){
        if(a[i]==a[i+1])ans++;
    }

    cout<<ans<<endl;

    return 0;
}