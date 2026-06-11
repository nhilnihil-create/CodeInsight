#include <bits/stdc++.h>

using namespace std;

int f(int n){
	if(n&1)return 3*n+1;
	return n/2;
}

const int N=1e6+6;

int a[N];

int main(){
	int n;
	cin >> n;
	map<int,int>m;
	a[1]=n;
	m[a[1]]++;
	for(int i=2;i<=N;i++){
		a[i]=f(a[i-1]);
		if(m[a[i]]){
			cout<<i;
			return 0;
		}
		m[a[i]]++;
	}
}