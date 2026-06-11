#include<iostream>
#include<vector>
using namespace std;
const long long M=998244353;
	vector<int> fakt(1000000);
int pomnozi(int a,int b){
	return ((long long) a*b) %M;
}
int zbroji(int a,int b){
	a+=b;
	if(a>=M) a-=M;
	return a;
}
int potenciraj(int a,int b){
	int r=1;
	while(b){
		if(b%2==1){
			r=pomnozi(r,a);
		}
		b/=2;
		a=pomnozi(a,a);
	}
	return r;
	
}
int povrh(int n,int k){
	int sol;
	sol=pomnozi(fakt[n], potenciraj(pomnozi(fakt[k], fakt[n - k]), M-2));
	return sol;
}
int main(){
	int n;
	long long k,a,b;
	cin>>n>>a>>b>>k;

	fakt[0]=1;
	for(int i=1;i<n+1;i++){
		fakt[i]=pomnozi(fakt[i-1],i);
	}
	int nacini=0;
	for(int i=0;i<=n;i++){
		long long temp= a*i;
		if((temp>k)) break;
		if((k-temp)%b)continue;
		long long j=(k-temp)/b;
		if (j>n) continue;
		nacini=zbroji(nacini,(pomnozi(povrh(n,i),povrh(n,j))));
	}
	cout<<nacini;
}