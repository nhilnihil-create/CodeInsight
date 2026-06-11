#include <bits/stdc++.h>
#include<iostream>
#define Ganesha ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define mp make_pair
#define lli long long int
using namespace std;
bool isPrime(lli n){
	if(n==1) return false;
	if(n==2||n==3||n==5) return true;
	if(n%2==0||n%3==0||n%5==0) return false;
	for(lli i=5;i*i<=n;i+=6){
		if(n%i==0||n%(i+2)==0) return false;
	}
	return true;
}
int main(){
    Ganesha
    bitset<4000001> S;
    int s=0,rs=0,i,n,x;
    S[0]=true;
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>x;
    	s+=x;
    	S=S|(S<<x);
    }
    rs=(s+1)/2;
    for(i=rs;i<=s;i++){
    	if(S[i]) break;
    }
    cout<<i<<endl;
    return 0;

}