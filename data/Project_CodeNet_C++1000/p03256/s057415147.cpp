#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef  long long ll;
int gcd(int f , int s){if(s==0)return f;else return gcd(s,f%s);}
int const N = 1000006;
ll const M = 998244353;
long double const ep = .000000000000000001;
int frqA[N] , frqB[N];
vector<int>G[N];
bool vis[N];
string s;
deque<int>q;
void del(int node){
	for(int i = 0 ; i < G[node].size() ; i++){
		int el = G[node][i];
		if(s[node]=='A')frqA[el]--;
		else frqB[el]--;
		if((frqA[el]==0||frqB[el]==0)&&!vis[el]){q.push_back(el);vis[el]=1;}
	}
}
int main() {
	
	int a , e;
	scanf("%d%d", &a , &e);
	cin >> s;
	s = "1"+s;
	for(int i = 0 ; i < e ; i++){
		int t , t1;
		cin >> t >> t1;
		G[t].pb(t1);
		G[t1].pb(t);
		if(t == t1){
			if(s[t]=='A')frqA[t]++;
			else frqB[t]++;
		}else {
			if(s[t]=='A')frqA[t1]++;
			else frqB[t1]++;
			if(s[t1]=='A')frqA[t]++;
			else frqB[t]++;
		}
	}
	for(int i = 1 ; i <= a ; i++)
		if(frqA[i] == 0 || frqB[i] == 0){q.push_back(i);vis[i]=1;}
	while(!q.empty()){
		del(q.front());
		q.pop_front();
	}
	for(int i = 1 ; i <= a; i++){
		if(!vis[i]){printf("Yes\n");return 0;}
	}
	printf("No\n");
	return 0;	
}