#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for( int i=a; i<b; i++ )
#define REP(i,n) rep(i,0,n)
#define INF 1000000
using lli = long long int;
using ulli = unsigned long long int;
typedef pair<int, int> P;

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

int count_comb(int a, int b, int c){
  if(a!=b && b!=c){ return 6; }
  else if( a==b && b==c){ return 1; }
  else{ return 3; }
}

string sub(string str, int start, int end){
  // require : start < end
  return str.substr(start, end-start+1);
}

vector<int> count( string s){
  vector<int> res(26);
  REP(i, s.size() ){
    int num = s[i] - 'a';
    res[ num ] ++; 
  }

  return res;
}

int main(){
  int n; cin >> n;
  string s; cin >> s;
  int res = 0;
  rep(i, 1, n){
    string s1 = sub(s, 0, i);
    string s2 = sub(s, i+1, n-1);

    vector<int> hist1 = count(s1);
    vector<int> hist2 = count(s2);
    int tmp = 0;
    REP(j, 26){
      if(hist1[j] && hist2[j]) tmp++;
    }
    if( tmp > res ){ res = tmp; }
  }

  cout << res << endl;
  return 0;
}