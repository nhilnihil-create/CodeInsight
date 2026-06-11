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
	int n;cin>>n;
	int l;l = 0;
	cout << 0 << endl;
	string sl;cin>>sl;
	if (sl == "Vacant"){	
		return 0;
	}
	int r;r = n - 1;
	cout << n - 1 << endl;
	string sr;cin>>sr;
	if (sr == "Vacant"){
		return 0;
	}
	while(1){
		int mid = (l + r) / 2;
		cout << mid << endl;
		string sm;cin>>sm;
		if (sm == "Vacant"){
			return 0;
		}
		if (((mid - l) % 2 == 0 && sl != sm) || ((mid - l) % 2 == 1 && sl == sm)){
			sr = sm;
			r = mid;
		}
		else{
			sl = sm;
			l =mid;
		}
	}
	return 0;
}