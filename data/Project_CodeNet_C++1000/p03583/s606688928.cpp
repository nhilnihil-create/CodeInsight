#include <bits/stdc++.h>

using namespace std;
using ll =long long;

#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cout << #x << " = " << (x) << endl;
void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1LL << 60;

//Write From this Line

int main()
{
	ll n; 
	cin >>  n; 
	ll a , b , c; 
	for(a = 1 ; a <= 3500 ; a ++) {
		for( b=  1 ; b <= 3500 ; b++){
			ll mother = 4 * a * b -(n*a) - (n*b);
			ll child = n * a * b ;
			if(mother == 0) continue;
			if(child % mother != 0 ){
				continue;
			}
			else{
				c = child / mother ;
				if( c <= 0 ) continue;
				cout << a << " " << b << " " ;
				cout << child/mother  << endl;
				return 0 ;
			}

		}
	}
	cout << - 1<< endl;

}
