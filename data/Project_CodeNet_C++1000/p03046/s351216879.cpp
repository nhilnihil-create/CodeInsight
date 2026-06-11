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
	int m; ll k; cin >> m >> k;
	
	if((1<<m) <= k){
		cout << -1 << endl;
		return 0;
	}
	if(m == 1){
		if(k >= 1) cout << -1;
		else{
			rep(i, pow(2,m)){
				cout << i  << " " << i << " ";
			}
		}
			
		return 0;
	}
	int i = 0;
	while(i<=pow(2,m)-1){
		if(i == k){
			i++;
			continue;
		} 
		cout << (i)<< " ";
		i ++;
	}
	cout << (k) << " ";
	i --;
	while(i>=0){
		if(i == k){
			i--;
			continue;
		} 
		cout << (i)<< " ";
		i--;
	}
	cout << (k);
}