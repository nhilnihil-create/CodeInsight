#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
using Graph = vector<vector<int>>;
int gcd(int a,int b){
	if(a%b==0){
		return b;
	}
	else{
		return gcd(b,a%b);
	}
}
int main(){
	int N,X;
	cin>>N>>X;
	vector<int> x(N);
	for(int i=0;i<N;i++){
		cin>>x[i];
	}
	int a=abs(X-x[0]);
	for(int i=1;i<N;i++){
		a=gcd(a,abs(X-x[i]));
	}
	cout<<a<<endl;
    return 0;
}