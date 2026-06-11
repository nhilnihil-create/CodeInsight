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
	vector<int> a(4);
	rep(i,4) cin >> a[i];
	sort(a.begin(),a.end());
	if(a[0] == 1) if(a[1] == 4) if(a[2]==7)if(a[3]==9){
		cout << "YES" << endl;
		return 0;
	}
	cout <<"NO"<<endl;
}
