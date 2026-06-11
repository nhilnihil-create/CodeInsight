#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for( int i=a; i<b; i++ )
#define REP(i,n) rep(i,0,n)
using lli = long long int;
using ulli = unsigned long long int;
typedef pair<lli,lli> P;

struct edge{ int u, v, cost; };
struct DirectedGraph
{
  int vertex_num;
  int edge_num;
  vector<edge> edge_list;
  vector< vector<int> > adj_list;
};

void displayVector(vector<lli> v)
{
	lli n = v.size();
	REP(i,n){
		cout << v[i] << " " ;
	}
	cout << endl;
}


int main(){
	int n, k; cin >> n >> k;
	double res = 0.0;
	REP(i, n){
		double tmp = i+1.0; double flip = 0;
		while(tmp < k){
			tmp *= 2; flip+=1.0;
		}

		res += 1.0/(double)n * pow(0.5, flip);
	}
	cout << setprecision(15) << res << endl;
}