#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<string>
#include<cmath>
#include<set>
#include<queue>
#include<deque>
#include<bitset>
#include<iomanip>
#include<cctype>
#include<map>
#include<cstring>
#include<bitset>
#include<cassert>
 
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,a,b) for (int (i)=a;(i)<(b);(i)++)
#define all(x) (x).begin(),(x).end()
 
using namespace std;
using ll = long long int;
 
const int inf = 1001001000;
const long long int Inf = 1001001001001001000;

template<typename T>
void print(vector<T> a){
	for (auto x:a){
		cout << x << " ";
	}
	cout << endl;
}

template<typename T>
void print2d(vector<vector<T>> a){
	for (auto v:a){
		for (auto x:v){
			cout << x << " ";
		}
		cout << endl;
	}
}



int main()
{
	ll n;
	cin >> n;
	for (ll a = 1; a < 3501;a++)
	{
		for (ll b = 1; b < 3501;b++){
			if (4 * a * b - n * a - n * b <= 0)
				continue;
			ll c = (n * a * b) / (4 * a * b - n * a - n * b);
			if (4*a*b*c == n*(a*b+b*c+c*a)){
				cout << a << " " << b << " " << c << endl;
				return 0;
			}
		}
	}
	return 0;
}