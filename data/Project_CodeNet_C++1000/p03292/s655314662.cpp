#pragma GCC optimize("Ofast,fast-math,unroll-loops")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;

#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()



int main() {
    IOS;
	
	int a,b,c;
	cin >> a >> b >> c;
	int q = a+b+c - max(max(a,b),c) - min(min(a,b),c);
	cout << max(max(a,b),c) - q + q - min(min(b,c),a);

}
