#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vl ;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;

#define rep(i,N) for(int i=0; i < (int)N; i++)
#define all(v) (v).begin(),(v).end()

const int INF = 1001001001;

int main(){
	int r, d, x; cin >> r >> d >> x;
	rep(i, 10){
		x = r * x - d;
		cout << x << endl;
	}
}