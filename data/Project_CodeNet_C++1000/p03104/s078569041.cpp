#pragma GCC optimize("Ofast")
#include <bits/stdc++.h> 
using namespace std;
 
typedef long long ll;
 
string int_to_string(int x) {
    stringstream ss;
	ss << x;
	string ni = ss.str();
	return ni;
}

int mod = 1e9 + 7;
ll power(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if(b & 1) {
			ans = (ans * a) % mod;
		}
		a = (a * a) % mod;
		b /= 2;
	}
	return ans;
}
 ll POW(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if(b & 1) {
			ans = ans * a;
		}
		a = a * a;
		b /= 2;
	}
	return ans;
}

int main() { 
	//8 4 2 1  //2 3   6 7  10 11   14 15 ...
	         //4 5 6 7   12 13
	         //8 9 10 11 12 13 14 15  24 25 26 27 
	ll n1, n2;
	cin >> n1 >> n2;
	//bool c = 0;
	//for (ll i = 2; i <= n2; i *= 2) {
		//if (i - 1 == n1) {
			//c = 1;
		//}
	//}
	//if (c) {
		//ll p = (n2 - n1) / 2;
		//ll x = 0;
		//if (p % 2 == 1) {
			//x = 1;
		//}
		//if ((n2 - n1) % 2 == 0) {
			//cout << (n1 ^ x);
		//}else {
		    //cout << ((n1 ^ n2) ^ x);
		//}
	//}else {
		//if ((n2 - n1 + 1) % 2 == 0) {
			//if (((n2 - n1) / 2) % 2 == 0) {
				//cout << 1;
			//}else {
				//cout << 0;
			//}
		//}else {
			//ll p1 = 0;
			//if (((n2 - n1 )/2) % 2 == 1) {
				//p1 = 1;
			//}
			//cout << (p1 ^ n2);
		//}
		
	if (n1 % 2 == 1 && n2 % 2 == 0) {
		ll p = 0;
		if (((n2 - n1 + 1 - 2)/ 2)% 2 == 1) {
			p = 1;
		}
		cout << ((n1 ^ n2) ^ p);
	}else if (n1 % 2 == 1){
		ll p = 0;
		if (((n2 - n1 + 1 - 1)/2) % 2 == 1) {
			p = 1;
		}
		cout << (n1 ^ p);
	}else if (n2 % 2 == 0) {
		ll p = 0;
		if (((n2 - n1 + 1 - 1) / 2) % 2 == 1) {
			p = 1;
		}
		cout << (n2 ^ p);
	}else {
		//ll p = 0
		if (((n2 - n1 + 1) / 2) % 2 == 1) {
			cout << 1;
		}else {
			cout << 0;
		}
	}
	//if ((n2 - n1) % 2 == 0) {
		//if (((n2 - n1) / 2) % 2 ==1){
			//cout << (n2 ^ 1);
		//}else {
			//cout << n2;
		//}
	//}else {
		//if (((n1 - n2)/2) % 2 == 0) {
			//cout << (n1 ^ n2);
		//}else {
			//cout << (n1 ^ 1);
		//}
	//}
	//}
	//for (ll i = 1; i <= n2; i = i * 2) {
		//ll p1 = (n1 - i + 2 * i - 1) / (2 * i);
		//ll p2 = (n2 - i + 2 * i) / (2 * i);
		//ll an1 = i + (p1 - 1)*(2 * i);
		//ll an2 = i + (p2 - 1)*(2 * i);
		//ll e = max(an1 + i - n1,(ll)0); 
		//ll cnt = (p2 - p1) * i + e;  
		//cnt -= max(an2 + i - n2,(ll)0);
		//if (cnt % 2) {
			//ans += i;
		//}
	//}
	//cout << ans;
}


//1 0 1 0 0 1  0  0 0 0 0 0 0   

//a + (n - 1)*d = an 
//an - a = nd - d
//an - a + d 
//elements in n2 - n1 

//  456 
//  123
//  333	
