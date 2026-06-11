#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin >> n >> k;
	int s=n-k;
	if(s%(k-1)==0){
		cout << s/(k-1)+1 << endl;
	}
	else{
		cout << s/(k-1)+2 << endl;
	}
}