#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

int main(){
	string s;cin>>s;
	int n = s.size();
	if(s =="keyence"){
		cout << "YES" << endl;
		return 0;
	}
	for(int i = 0; i <= n; i++) {
		for(int j = i + 1; j < n; j++) {
			string sub1 = s.substr(0,i);
			string sub2 = s.substr(j);
			if(sub1 + sub2 == "keyence"){
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}