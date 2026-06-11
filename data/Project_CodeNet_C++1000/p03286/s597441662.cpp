#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
	cout << fixed << setprecision(10);
	int n;
	cin >> n;
  	vector<int> v;
	while(n!=0){
		//cout << n << endl;
		if(n%(-2)==0) v.push_back(0);
		else v.push_back(1);
		if(n<0){
			n *= -1;
			n += n%2;
			n /= 2;
		}else{
			n /= (-2);
		}
		if(n==1){
			v.push_back(1);
			break;
		}
		if(n==-1){
			v.push_back(1);
			v.push_back(1);
			break;
		}
	}
	reverse(v.begin(),v.end());
	if((int)v.size()==0) v.push_back(0);
	for(auto u : v){
		cout << u;
	}
	cout << endl;
	return 0;
}
