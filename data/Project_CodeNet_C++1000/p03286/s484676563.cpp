#include<bits/stdc++.h>

using namespace std;

int n;
string ans;

int main(){
	cin >> n;
	while(n != 0){
		if(n % 2 == 0){
			ans = "0"+ans;
		}else{
			n--;
			ans = "1"+ans;
		}
		n /= -2;
	}
	if(ans == "") ans = "0";
	cout << ans << endl;
}