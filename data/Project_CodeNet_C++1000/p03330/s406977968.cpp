#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl

template<typename T>
void trace(T *a, int s, int n) {
    for (int i=s; i<n; i++) {
	cout<<a[i]<<" ";
    }
    cout<<endl;
}



typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 505;

int n,c;
int cost[maxn][maxn];
int g[maxn][maxn];

vector<vector<int>> ways;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin>>n>>c;
    for (int i=1; i<=c; i++) {
	for (int j=1; j<=c; j++) {
	    cin>>cost[i][j];
	}
    }
    vector<map<int,int>> mp(3);
    
    for (int i=1; i<=n; i++) {
	for (int j=1; j<=n; j++) {
	    cin>>g[i][j];
	    mp[(i+j)%3][g[i][j]]++;
	}
    }

    vector<int> v;
    for (int i=1; i<=c; i++) {
	v.push_back(i);
    }

    for (int i=0; i<c; i++) {
	for (int j=i+1; j<c; j++) {
	    for (int k=j+1; k<c; k++) {
		ways.push_back({v[i],v[j],v[k]});
	    }
	}
    }


    // watch(ways.size());
    
    int best = 1e9;

    for (auto x: ways) {
	
	do {

	    // for (int i: x) cout<<i<<" ";
	    // cout<<endl;
	    vector<int> cur(3);
	    cur[0]=x[0];
	    cur[1]=x[1];
	    cur[2]=x[2];
	    int tot=0;

	    for (int i=0; i<3; i++) {
		for (auto p: mp[i]) {
		    int color = p.first;
		    int freq = p.second;
		    tot += cost[color][cur[i]]*freq;
		}
	    }

	    best=min(best,tot);
	} while (next_permutation(x.begin(), x.end()));

    }



    cout<<best<<endl;
    

    return 0;
}
