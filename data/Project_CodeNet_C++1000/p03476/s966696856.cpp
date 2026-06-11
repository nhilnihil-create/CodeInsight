//q069.cpp
//Tue Sep  1 20:19:27 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
#define MOD 1000000007
#define rep(i,n) for (int i=0;i<(n);++i)

using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	int q;
	cin >> q;

	vector<int> prime(100100,1);
	for (int i=2;i<100100;i++){
		if (prime[i]==1){
			for (int j=i*2;j<100100;j=j+i){
				prime[j] = 0;
			}
		}
	}

	vector<int> a(100010,0);
	rep(i,100010){
		if (i%2==1 && prime[i] && prime[(i+1)/2]){
			a[i] = 1;
		}
	}
	a[1] = 0;

	vector<int> rui(100001,0);
	for (int i=1;i<100001;i++){
		rui[i] = rui[i-1]+a[i];
	}

	rep(i,q){
		int l,r;
		cin >> l >> r;
		cout << rui[r]-rui[l-1] << endl;
	}

}