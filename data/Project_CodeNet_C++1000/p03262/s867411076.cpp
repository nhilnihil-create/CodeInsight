#include <bits/stdc++.h>
using namespace std;
int my_gcd(int a,int b){
	while(b!=1){
		if(a%b == 0) return b;
		int temp = a;
		a = b;
		b = temp%b;
	}
	return 1;
}

int main(){
	int n,x,a;
	
	cin >> n >> x;
	int k = n;
	if(n==1) {cin >> a; cout << abs(x-a); return 0;}
	vector<int> v;
	v.push_back(x);
	while(n--){
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	int g = my_gcd(abs(v[1]-v[0]),abs(v[2]-v[1]));
	for(int i = 2; i<k;i++){
		g = my_gcd(v[i+1]-v[i],g);
	}
	cout << g;
	
}
		
		
    
	

