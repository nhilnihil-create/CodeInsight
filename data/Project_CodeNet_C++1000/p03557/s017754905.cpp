#include <bits/stdc++.h>
using namespace std;
#define FOR(i,o,n) for(long long i = o;i<n;i++)
#define oneforall ios::sync_with_stdio(false);cin.tie(0);
#define all(v) (v).begin(),(v).end()
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) long long __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
#define int long long 
const long long inf=1e18;
void in(){} template <typename T,class... U> void in(T &t,U &...u){ cin >> t; in(u...);}
void out(){cout << "\n";} template <typename T,class... U> void out(const T &t,const U &...u){ cout << t; if(sizeof...(u)) cout << " "; out(u...);}
typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;
typedef vector<pair<long, long > > vpll;
typedef vector<pair<int, int > > vpii;
#define FORR(x,arr) for(auto& x:arr)
#define ZERO(a) memset(a,0,sizeof(a))





//3111111111111111111111111111111

	void solve(){

		
		ini(n);
		vi mortyu(n);
		vi mortym(n);
		vi mortyd(n);
		FOR(i,0,n){
			in(mortyu[i]);
		}
		FOR(i,0,n){
			in(mortym[i]);
		}
		FOR(i,0,n){
			in(mortyd[i]);
		}
		sort(all(mortym),greater<int>());
		sort(all(mortyd),greater<int>());

		vi pref(n);
		FOR(i,0,n){
			int tmp = mortym[i];
			int ll = 0;
			int rr = n-1;
			while(ll<=rr){
				int mid = ll+(rr-ll)/2;
				if(mortyd[mid]>tmp)ll = mid+1;
				else rr = mid-1;
			}
			pref[i] = ll;
		}
		FOR(i,1,n){
			pref[i]+=pref[i-1];
		}
		int rick = 0;
		FOR(i,0,n){
			int tmp = mortyu[i];
			int ll = 0;
			int rr = n-1;
			while(ll<=rr){
				int mid = ll+(rr-ll)/2;
				if(mortym[mid]>tmp)ll = mid+1;
				else rr = mid-1;
			}
			if(ll == 0)continue;
			else{
				//out(tmp,ll);
				rick+=pref[ll-1];
			}
		}
		out(rick);









		
		
	}























int32_t main() {
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall 
	oneforall

	solve();
	


	return 0;
}
