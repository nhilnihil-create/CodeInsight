#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	int ans=0;
	if(N==10 || N==100 || N==1000 || N==10000 || N==100000)ans=10;
	else{
		while(N>0){
			ans+=N%10;
			N/=10;
		}
	}
	cout << ans << endl;
	return 0;
}