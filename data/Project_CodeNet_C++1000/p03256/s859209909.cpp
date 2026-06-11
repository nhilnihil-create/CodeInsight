#include <bits/stdc++.h>
#define pb push_back

using namespace std;

typedef pair<int,int> pii;
const int MAXN  = 2*1e5 + 10;

map < pii , bool > mp;
int N , M , cntA[MAXN] , cntB[MAXN] , rem[MAXN];
vector <int> gr[MAXN] , removed;
string tp;


int main(){
	cin >> N >> M >> tp;
	
	for(int i=0; i<M; i++){
		int u,v; cin >> u >> v;u--;v--;	
		 map< pii , bool >:: iterator it = mp.find(pii(u,v));
		if(it != mp.end()) continue;

		mp[pii(u,v)] = true;
		mp[pii(v,u)] = true;
		gr[u].pb(v);
		gr[v].pb(u);

		if(tp[u] == 'A') 	cntA[v]++;
		else 			cntB[v]++;

		if(tp[v] == 'A') 	cntA[u]++;
		else 			cntB[u]++;		
	}	
	//cout << endl;
	for(int i=0; i<N; i++)
		if(min(cntA[i] , cntB[i]) == 0) rem[i] = 1 , removed.pb(i);



	for(int i=0; i<removed.size(); i++){
	        if(tp[removed[i]] == 'A'){
			for(int j=0; j<gr[removed[i]].size(); j++){
				int cur = gr[removed[i]][j];
				if( (--cntA[cur] == 0) && !rem[cur]) removed.pb(cur) , rem[cur] = 1;	
			}
		}
		else{
			for(int j=0; j<gr[removed[i]].size(); j++){
				int cur = gr[removed[i]][j];
				if( (--cntB[cur] == 0) && !rem[cur]) removed.pb(cur) , rem[cur] = 1;	
			}
		}
	}		

	
	if(removed.size() == N) cout << "No" << '\n';		
	else cout << "Yes" << '\n';
	return 0;
}