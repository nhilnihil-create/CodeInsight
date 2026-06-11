#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int c=0;
	int v_n = n;
	while(v_n!=0){
		v_n /= 10;
		c ++;
	}
	vector<int> a(c);
	for(int i =0; i < c; i++){
		a.at(i) = n %10;
		n /= 10;
	}
	int sum = 0;
	int zero = 0;
	for(int i = 0; i < (c-1); i++){
		if(a.at(i) == 0) zero++;
		sum += a.at(i);
	}
	if(zero == c-1 && a.at(c-1) == 1){
		sum += 10;
	}else{
		sum += a.at(c-1);
	}
	cout << sum << endl;
}
