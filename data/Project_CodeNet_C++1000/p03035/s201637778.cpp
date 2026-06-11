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
	int a, b; cin >> a >> b;
	if(a>=13) cout << b << endl;
	else if(a >= 6) cout << b/2 << endl;
	else cout << 0 << endl; 
}