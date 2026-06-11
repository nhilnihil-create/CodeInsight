#include <bits/stdc++.h>

using namespace std;
using ll =long long;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
const ll INF = 1LL << 60;
const int mod = 1e9+7;
//Write From this Line

int main()
{
	int n; 
	cin >> n; 
	int left = 0 ;
	int right = n ;
	cout << 0 << endl;
	string bef ;
	cin >> bef ;
	if(bef == "Vacant") {
		cout << endl;
		return 0 ;
	}
	int bef_num = 0 ;
	while(right - left > 1){
		int c = (left + right ) / 2; 
		cout << c << endl;
		string s ;
		cin >> s ;
		if(s=="Vacant"){
		cout << endl;
			return 0 ;
		}
		int diff = c;
		if(diff % 2 == 0){
			if(s==bef){
				left = c ;
			} else {
				right = c;
			}
		} else {
			if(s == bef){
				right = c;
			} else {
				left = c;
			}
		}
	}
	cout << left << endl;
	string s;
	cin >> s ;
	if(s=="Vacant"){
		cout << endl;
		return 0 ;
	}
	cout << right << endl;
	cin >> s;
	if(s=="Vacant"){
		cout << endl;
		return 0 ;
	}

}
