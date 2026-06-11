#include <bits/stdc++.h>
#define newl "\n"
using namespace std;
using lli = long long int;
using vvint = vector <vector <int>>;
const int mod = 1e9 + 7;

const int N = 2e5 + 1;

void solve(){
	int n,m;
	cin >> n >> m;
	vector <vector <pair <int,int>>> p(n + 1);
	for(int i = 0;i < m;++i){
		int P,Y;
		cin >> P >> Y;
		p[P].push_back({Y,i + 1});
	}
	vector <string> out(m + 1,"");
	for(int i = 1;i <= n;++i){
		sort(p[i].begin(),p[i].end());
		for(int j = 0;j < (int)p[i].size();++j){
			string i1 = to_string(i);
			string ap = "";
			for(int k= 0;k < 6 - (int)i1.length();++k){
				ap = ap + "0";
			}
			reverse(i1.begin(),i1.end());
			i1 = i1 + ap;
			ap = "";
			string j2 = to_string(j + 1);
			for(int k = 0;k < 6 - (int)j2.length();++k){
				ap = ap + "0";
			}
			reverse(j2.begin(),j2.end());
			j2 = j2 + ap;
			out[p[i][j].second] = j2 + i1;
			reverse(out[p[i][j].second].begin(),out[p[i][j].second].end());
		}
	}
	for(int i = 1;i <= m;++i) cout << out[i] << newl;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(10);
	#ifdef EXECUTE_LOCALLY
		   freopen("in.txt","r",stdin);
	#endif
	int t = 1;
	//cin >> t;
	while(t--) solve();
	#ifdef EXECUTE_LOCALLY
    	cout << setprecision(3) << "program time: " << (double)clock() / CLOCKS_PER_SEC << newl;
	#endif
	return 0;
}
