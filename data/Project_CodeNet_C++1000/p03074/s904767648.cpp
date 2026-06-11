#include <bits/stdc++.h>
#define INF pow(10, 9) + 7
#define rep(i, N) for(ll i = 0; i < N; i++)
#define rep2(i, j, k) for(ll i = j; i < k; i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define chmax(x, y) x = max(x, y)
#define print(x) cout << x << "\n"
#define ALL(v) v.begin(), v.end()
#define SUM(v) accumulate(ALL(v), 0)
#define MAX(v) *max_element(ALL(v))
#define MIN(v) *min_element(ALL(v))
#define SORT(v) sort(ALL(v))
#define REV(v) reverse(ALL(v))
typedef long long ll;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vs = vector<string>;
using vvs = vector<vector<string>>;

void solve(){
	
	ll N, K, cnt, num;
	cin >> N >> K;
	string S;
	cin >> S;
	
	vl v(0);
	ll num0 = 0;
	ll ans = 0;
	ll ind = 0;
	
	if(S[0] == '1'){
		
		while(ind < N){
			
			cnt = 0;
		
			while(ind < N && S[ind] == '1'){
				cnt += 1;
				ind += 1;
			}
			v.push_back(cnt);
			
			cnt = 0;
			
			while(ind < N && S[ind] == '0'){
				cnt += 1;
				ind += 1;
			}
			v.push_back(cnt);
			num0 += 1;
		
		}
		
		cnt = 0;
		num = v.size();
		
		if(num0 <= K) ans = N;
		
		else{
			
			rep(i, 2 * K + 1) cnt += v[i];
			
			rep(i, num0 - K + 1){
				
				chmax(ans, cnt);
				cnt -= v[2 * i];
				cnt -= v[2 * i + 1];
				cnt += v[2 * i + 2 * K + 1];
				if(2 * i + 2 * K + 1 + 1 < num)  cnt += v[2 * i + 2 * K + 1 + 1];
			
			}
			
		}

	}
	
	else{
		
		ind = 0;
		
		while(ind < N){
			
			cnt = 0;
		
			while(ind < N && S[ind] == '0'){
				cnt += 1;
				ind += 1;
			}
			v.push_back(cnt);
			
			cnt = 0;
			
			while(ind < N && S[ind] == '1'){
				cnt += 1;
				ind += 1;
			}
			v.push_back(cnt);
			num0 += 1;
		
		}
		
		cnt = 0;
		num = v.size();
		
		if(num0 <= K) ans = N;
		
		else{
			
			rep(i, 2 * K) cnt += v[i];
			
			rep(i, num0 - K + 1){
				
				chmax(ans, cnt);
				if(i == 0)  cnt -= v[0];
				else{
					cnt -= v[2 * i - 1];
					cnt -= v[2 * i];
				}
				cnt += v[2 * i + 2 * K];
				if(2 * i + 2 * K + 1 < num)  cnt += v[2 * i + 2 * K + 1];
			
			}
			
		}

	}
	
	print(ans);

}	

int main(){
    
    fastio;
	solve();
    
	return 0;
	
}
