#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>
#define F first
#define S second

using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n,h,w;
	cin >> n >> h >> w;
	cout << (n-h+1)*(n-w+1) << endl;
	return 0;
}