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
	int n ;
	cin >> n ;
	vector<int> b(n);
	rep(i,n){
		cin >> b[i];
		b[i] --;
	} 
	vector<int> ans(n);
	int index =  n - 1;
	int good = -1;
	while(1){
		good = - 1;
		rep(i,b.size()){
			if(b[i] == i){
				good = i ;
			}
		}
		if(good != -1){
			ans[index] = good ;
			index -- ;
			if(index == -1){
				break;
				//答えの出力に映る
			}
		} else {
			cout << -1 << endl;
			return 0 ;
		}
		//goodをのぞいた配列を作る。
		b.erase(b.begin()+good,b.begin()+good+1);
	}
	rep(i,n){
		cout << ans[i]+1 << endl;
	} 
}
