#include <bits/stdc++.h>
using namespace std;
#define dhoom ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);  
typedef long long ll;
typedef long double ld;
const ll inf = 1e18;
const int nax = 2e6 + 7;
const ll mod = 1e9 + 7;
//ll tree[4 * nax];
//9uS-22RSwk7gQqh
int a[2][230];
//int t[100005] , x[100005] , y[100005];
int gcd(int a , int b , int c)
{
		int x = __gcd(a ,b);
		return __gcd(x , c);
}

int main(){
	dhoom;
	char a[3][3];
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++)
			cin >> a[i][j];	
	}
	cout << a[0][0] << a[1][1] << a[2][2];
	return 0;
	
}
