#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

vector<Int> a = {2, 3, 4, 6, 8, 9, 10, 12};
vector<vector<Int>> b = {
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 0, 0},
	{1, 0, 1, 0, 0, 0, 0, 0},
	{1, 0, 1, 1, 0, 0, 0, 0},
	{1, 0, 1, 0, 1, 0, 1, 0},
	{1, 1, 1, 1, 0, 1, 0, 0},
	{1, 1, 1, 1, 0, 1, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 0},
	{1, 1, 1, 1, 1, 1, 1, 1}
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	Int n; cin >> n;
	if(n == 3){
		cout << 2 << " " << 5 << " " << 63 << "\n";
	}else if(n == 4){
		cout << 2 << " " << 5 << " " << 20 << " " << 63 << "\n";
	}else{
		Int m = n/8;
		Int r = n - m*8;
		for(Int i=0; i<m; ++i)
			for(Int j=0; j<8; ++j)
				cout << 12*i + a[j] << " ";
		for(Int i=0; i<8; ++i)
			if(b[r][i] == 1)
				cout << 12*m + a[i] << " ";
		cout << "\n";
	}
}