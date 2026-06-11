#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for( int i=a; i<b; i++ )
#define REP(i,n) rep(i,0,n)
#define INF 1000000000000
using lli = long long int;
using ulli = unsigned long long int;
typedef pair<lli,lli> P;

struct edge{ int u, v; lli cost; };
struct DirectedGraph
{
  int vertex_num;
  int edge_num;
  vector<edge> edge_list;
  vector< vector<int> > adj_list;
	vector< vector<lli> > distance_matrix;
};

template <typename T>
vector<int> argsort(const vector<T> &v) {

  // initialize original index locations
  vector<int> idx(v.size());
  iota(idx.begin(), idx.end(), 0);

  // sort indexes based on comparing values in v
  sort(idx.begin(), idx.end(),
       [&v](int i1, int i2) {return v[i1] < v[i2];});

  return idx;
}

template<typename T>
void displayVector(vector<T> v)
{
	lli n = v.size();
	REP(i,n){
		cout << v[i] << " " ;
	}
	cout << endl;
}


int main(){
	int N, M; cin >> N >> M;
	vector<lli> a(N); REP(i, N){ cin >> a[i]; }
	vector<P> x(M); REP(i, M){ cin >> x[i].first >> x[i].second; }

	sort(x.begin(), x.end(),
       [&x](P p1, P p2) {return p1.second > p2.second;});

	vector<lli> d;
	int iter = 0;
	while( d.size() <= N && iter<M){
		REP(i, x[iter].first ){ d.push_back( x[iter].second ); }
		iter++;
	}
	d.resize(N);

	sort(a.begin(), a.end());
	REP(i, N){
		if(a[i] < d[i]){ a[i] = d[i]; 
		} else{ break; }
	}

	cout << accumulate(a.begin(), a.end(), 0LL) << endl;
	return 0;
}