#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main(){
	int n, ans = 0, fbra = 0, fbna = 0, nbra = 0;
	string in;
	cin >> n;
	rep(i, n){
		cin >> in;
		rep(j, in.size()){
			if(j != 0 && in[j] == 'B' && in[j-1] == 'A') ans++;
		}
		if(in[0] == 'B' && in.back() == 'A') fbra++;
		else if(in[0] == 'B') fbna++;
		else if(in.back() == 'A') nbra++;
	}
	if(fbra == 0) ans += min(fbna, nbra);
	else{
		if(fbna != 0 || nbra != 0){
			ans += min(fbra + fbna, fbra + nbra);
		}else{
			ans += fbra - 1;
		}
	}
	
	cout << ans << endl;
	
}