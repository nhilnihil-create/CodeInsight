#include <bits/stdc++.h>
using namespace std;

int main(){
	long long A,B,C,ans=0;
	cin >> A >> B >> C;
	
	ans+=B;
	ans+=min(C,B);
	C-=B;
	if(C>0)ans+=min(C,A);
	C-=A;
	if(C>0)ans++;
	cout << ans << endl;
	
	return 0;
}