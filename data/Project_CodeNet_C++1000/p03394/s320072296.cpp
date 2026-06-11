//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF INT_MAX
#define LLINF LLONG_MAX
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
    for (T& x: vec) { is >> x; }
    return is;
}

int main() {
	ll ans = 0;
	ll tmp;
	int n;
	cin >> n;
	if(n==3) cout << "2 3 25" << endl;
	else{
		int now = 0;
		if(n % 2 == 1){
			cout << "30 ";
			now++;
		}
		REP1(x, 30000){
			if(x%30 >= 15 || x%30==0) continue;
			if(x%2 == 0 || x%3 == 0 || x%5 == 0){
				cout << x << " " << x - 2 *(x%30) + 30 << " ";
				now +=2 ;
			}
			if(now == n) break;
		}
		cout << endl;
		//cout << now;
	}
	//cout << ans << endl;
}