#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
using ll = long long;


template<class T>inline bool chmax(T& a, T b){if(a<b) { a=b;return true; } return false;}
template<class T>inline bool chmin(T& a, T b){if(a>b) { a=b;return true; } return false;}

int main(){
	ll n,m;cin >> n >> m;
	if(n == 1 && m == 1){
		cout << 1 << endl;
	}else if(n == 1 && m >= 3){
		cout << m-2 << endl;
	}else if(m == 1 && n >= 3){
		cout << n-2 << endl;
	}else if(n>=3 && m>=3){
		cout << (m-2)*(n-2) << endl;
	}else{
		cout << 0 << endl;
	}
}
