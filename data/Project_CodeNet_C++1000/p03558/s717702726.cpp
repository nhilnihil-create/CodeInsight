#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define ld long double
#define fast ios_base::sync_with_stdio(false) ;cin.tie(NULL);cout.tie(NULL)
#define F(i,a,b) for(int i= (int)(a); i<(int)(b);i++)
#define FI(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define what_is(x) cerr << #x << " is " << x << endl;
#define ms(x,a) memset(x,(int)(a),sizeof(x))
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pii pair<int,int>
#define vi vector<int >
#define pb push_back
#define endl '\n'
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
const int N = 1e6+7 ;
string s ;
bool vis[N] ;
deque<pii> dq ;
int main(){fast ;
	int k ;
	cin >> k ;
	dq.push_front({1,1}) ;
	while(!dq.empty()){
		pii now = dq.front() ;
		dq.pop_front() ;
		if(vis[now.ff])
			continue ;
		vis[now.ff] = true ;
		if(!now.ff){
			return cout << now.ss << endl , 0 ;
		}
		dq.push_front({now.ff * 10 % k , now.ss}) ;
		dq.push_back({(now.ff+1) % k , now.ss+1}) ;
	}
}


