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
	int n, m; cin >> n >> m;
	vector<int> p(m);
	vector<lli> y(m) ;
	vector< vector<lli> > id_list(n);

	REP(i, m){ 
		cin >> p[i] >> y[i]; 
		id_list[p[i]-1].push_back(y[i]);
	}

	REP(i, n){
		if( id_list[i].size() != 0 ){
			sort( id_list[i].begin(), id_list[i].end() );
		}
	}

	REP(i, m){
		lli out = 1000000 * lli( p[i] ) + distance(id_list[p[i]-1].begin(), lower_bound( id_list[p[i]-1].begin() , id_list[p[i]-1].end(), y[i]) ) + 1;
		cout << setfill('0') << right << std::setw(12) << out << endl;
	}

  return 0;
}