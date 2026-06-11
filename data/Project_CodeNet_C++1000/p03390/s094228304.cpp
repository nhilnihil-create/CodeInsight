#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int Q;
	cin >> Q;
	while(Q--){
		long long A,B;
		long long int s,tmp,ans;
		cin >> A >> B;
		s = A*B ;
		tmp = (long long int)sqrt(s);
		if( tmp*tmp < s ){
			if(tmp*(tmp+1)< s) ans = tmp*2;
			else ans = tmp*2 -1;
			if(A <= tmp || B <= tmp) ans--;
		}
		else{
			if( (tmp-1) * tmp <s) ans = (tmp-1)*2;
			else ans = tmp*2 -1;
			if(A <= (tmp-1) || B <= (tmp-1)) ans--;
		}
        cout << ans << endl;
	}
}
