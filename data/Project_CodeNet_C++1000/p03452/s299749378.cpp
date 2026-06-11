#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <cstdio>
#include <climits>
#include <complex>
#include <cstdint>
#include <tuple>

#define M_PI       3.14159265358979323846

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }
inline int readInt() { int x; scanf("%d", &x); return x; }

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;

//container util

//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007

vector<vector<pair<int, int>>> G(100010);
int dist[100010];
bool visited[100010];

bool bfs(int v, int d){
    if(visited[v] && d != dist[v]) return false;
    if(visited[v] && d == dist[v]) return true;
    
    visited[v] = true;
    dist[v] = d;
    
    REP(i, (int)G[v].size()){
        if( !bfs(G[v][i].first, d + G[v][i].second)) return false;
    }
    return true;
}

int main() {
    
    int N = readInt(), M = readInt();
    
    REP(i, M){
        int l = readInt(), r = readInt(), d = readInt();
        l--; r--;
        
        G[l].push_back(make_pair(r, d));
        G[r].push_back(make_pair(l, -d));
    }
    
    REP(i, 100010) visited[i] = false;
    REP(i, 100010) dist[i] = -1 * INT_MAX;
    REP(i, N){
        if(!visited[i]){
            if(!bfs(i, 0)){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
	return 0;
}