// C - Base -2 Number
#include <bits/stdc++.h>
using namespace std;

int main(){
	int N; cin>>N;
	string ans = "";
	int p = -2;
	while(N != 0){
		int r = N % p; N /= p;
		if(r < 0){ r -= p; N++; }
		ans = to_string(r) + ans;
	}
	if(ans == "") ans = "0";
	cout<< ans <<endl;
}
