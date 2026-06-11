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

vector<lli> argsort(vector<lli> v)
{
	lli n = v.size();
	vector<lli> indices(n);
	REP(i,n){ indices[i] = i; }

	sort(indices.begin(), indices.end(), [&v](lli i1, lli i2) {
        return v[i1] > v[i2];
  });

	return indices;
}


int main(){
	int n; cin >> n;
	vector<lli> a(n), b(n), c(n);
	REP(i,n){ cin >> a[i]; }
	REP(i,n){ cin >> b[i]; }
	REP(i,n){ cin >> c[i]; }

	sort(a.begin(), a.end() );
	sort(c.begin(), c.end() );

	lli res = 0;
	REP(i, n){
		lli tmp_b = b[i];
		res += (lower_bound(a.begin(), a.end(), b.at(i)) - a.begin())
                  * (c.end() - upper_bound(c.begin(), c.end(), b.at(i)));;
	}
	cout << res << endl;
  return 0;
}