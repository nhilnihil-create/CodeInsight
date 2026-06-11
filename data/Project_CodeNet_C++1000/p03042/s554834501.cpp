#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define read(x) int x; cin>>x;
#define print(x) for(int i=0; i<(int) x.size(); i++) cout<<x[i]<<" "; cout<<endl;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;

const ll INFLL = (ll) 1e16;
const int INF = (int) 1e8;

bool is_month(int m) {
	return m>=1 && m<=12;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin>>s;
	
	int first = stoi(s.substr(0, 2));
	int second = stoi(s.substr(2));
	if(is_month(first) && is_month(second)) cout<<"AMBIGUOUS"<<endl;
	else if(is_month(first)) cout<<"MMYY"<<endl;
	else if(is_month(second)) cout<<"YYMM"<<endl;
	else cout<<"NA"<<endl;
	return 0;
}
