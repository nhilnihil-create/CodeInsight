#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll amari = 1e9+7;
#define ben(a) a.begin(),a.end()

int main(){
	int n;
	string a,b,c;
	cin >> n >> a >> b >> c;
	int sum = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == b[i] && b[i] == c[i] && a[i] == c[i])sum += 0;
		else if(a[i] != b[i] && b[i] != c[i] && a[i] != c[i])sum += 2;
		else sum++;
	}
	cout << sum << endl;
	return 0;
}