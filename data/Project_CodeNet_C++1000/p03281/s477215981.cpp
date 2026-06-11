#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	int counts = 0;
	int countsA = 0;
	for(int i = 1; i <= n; i++){
		counts = 0;
		if(i%2 == 0) continue;
		else{
			for(int j = 1; j <=n; j++){
			if(i%j == 0) counts++;
		}
		if(counts == 8) countsA++;
	}
	}
	cout << countsA << endl;
}