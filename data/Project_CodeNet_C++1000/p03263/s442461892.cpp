#include <bits/stdc++.h>
using namespace std;
#define FOR(i,o,n) for(long long i = o;i<n;i++)
#define oneforall ios::sync_with_stdio(false);cin.tie(0);
#define all(v) (v).begin(),(v).end()
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) long long __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
#define int long long 
const long long INF=1e18;
void in(){} template <typename T,class... U> void in(T &t,U &...u){ cin >> t; in(u...);}
void out(){cout << "\n";} template <typename T,class... U> void out(const T &t,const U &...u){ cout << t; if(sizeof...(u)) cout << " "; out(u...);}
typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;
typedef vector<pair<long, long > > vpll;
typedef vector<pair<int, int > > vpii;
#define FORR(x,arr) for(auto& x:arr)

/*
bool isprime(int x){
	for(int i = 2;i*i<=x;i++){
		if(x%i == 0)return false;
	}
	return x!=1;
}
int gcd(int a, int b) 
{ 
    if (a == 0) 
       return b; 
    if (b == 0) 
       return a; 
   
    if (a == b) 
        return a; 
   
    if (a > b) 
        return gcd(a-b, b); 
    return gcd(a, b-a); 
} 
void dfs(int x,int y){
		if(x == n+1){
			int tmp = 0;
			FOR(i,0,k){
				if(tmp1[mortyy[i]]-tmp1[morty[i]] == mortyyy[i])tmp+=mortyyyy[i];
			}
			rick = max(rick,tmp);
			return ;
		}
		int i;
		for(i = y;i<=n1;i++){
			tmp1[x] = i;
			dfs(x+1,i);
		}
	}
*/


//3111111111111111111111111111111


	void solve(){

		ini(n);
		ini(n1);
		vector<pair<pair<int,int>,pair<int,int>>> morty1;
		int morty[n][n1];
		int rick = 0;
		FOR(i,0,n)FOR(i1,0,n1)in(morty[i][i1]);
		FOR(i,0,n)FOR(i1,0,n1-1){
			if(morty[i][i1]%2 == 1){
				rick++;
				morty[i][i1+1]++;
				morty1.push_back(make_pair(make_pair(i+1,i1+1),make_pair(i+1,i1+2)));
			}
		}
		FOR(i,0,n-1){
			if(morty[i][n1-1]%2){
				rick++;
				morty[i+1][n1-1]++;
				morty1.push_back(make_pair(make_pair(i+1,n1),make_pair(i+2,n1)));
			}
		}
		out(rick);
		FOR(i,0,rick){
			out(morty1[i].first.first,morty1[i].first.second,morty1[i].second.first,morty1[i].second.second);
		}













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