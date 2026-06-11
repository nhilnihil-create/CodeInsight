#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define rep(i, n) for(int i = 0; i < n; i++)
#define repp(i, n) for(int i = 1; i <= n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define pb push_back
#define mp make_pair
#define riverse(v) reverse((v).begin(), (v).end())
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;
using vll = vector<ll>;
const ll MOD = 1e9+7;
vi alphabet = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
               'n','o','p','q','r','s','t','u','v','w','x','y','z'};
 
int main() {
	int N;
  	cin >> N;
  	vi a(N);
  	rep(i,N) cin >> a[i];
  	map<int,int> sum;
	rep(i,N){
    	int x=a[i];
      	if(sum.count(x)) sum.at(x)++;
      	else sum[x] = 1;
    }
  	int ans=0;
  	for (auto p : sum) {
 	 	auto key = p.first;
 	 	auto value = p.second;
      	if(value < key) ans += value;
      	else ans += value - key;
	}
  	cout << ans << endl;
}