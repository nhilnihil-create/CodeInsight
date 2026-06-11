#include <bits/stdc++.h>

#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define sz(a) int((a).size())
#define endl '\n'

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	#ifndef ONLINE_JUDGE
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
//	#endif
	int g[3][3];
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			cin>>g[i][j];
		}
	}
	int b[3];
	bool ok=false;
	for(int i=0;i<3;++i){
		bool tmp = true;
		for(int j=0;j<3;++j){
			b[j]=g[i][j];
		}
		for(int j=0;j<3;++j){
			int a = g[j][0]-b[0];
			for(int k=1;k<3;++k){
				if(g[j][k] != a+b[k])
					tmp=false;
			}
		}
		if(tmp)
			ok=true;
	}
	cout<<(ok?"Yes":"No")<<endl;
	return 0;
}