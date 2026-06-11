#include <bits/stdc++.h>
using namespace std;
string a,b,c;
int n,w;
unordered_map<char,int> m[100];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> a >> b >> c;
	for (int i=0;i<n;++i){
		++m[i][a[i]];
		++m[i][b[i]];
		++m[i][c[i]];
		w+=m[i].size()-1;
	}
	cout << w;
}