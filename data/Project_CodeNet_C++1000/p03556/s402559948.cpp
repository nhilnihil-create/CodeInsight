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
	lli n; cin >> n;
	lli out = 1;
	while(1){
		if(n < out*out ){
			cout << (out-1)*(out-1) << endl;
			break;
		}
		out += 1;
	}
  return 0;
}