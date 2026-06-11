#include <iostream>
#include <ostream>
#include <istream>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <vector>
#include <set>
#define pb push_back
#define ppb pop_back
using namespace std;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define forv(i, v) forn(i, v.size())
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"
#define pi 3.1415926535897932
#define NMAX 100005
#define INF 1000000007
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
int K,dist[100000];
deque<int> todo;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>K;
	for(int i=0; i<K; i++)dist[i]=INF;
	dist[1]=1;
	todo.pb(1);
	while(todo.size()) {
		int x=todo.front();
		todo.pop_front();
		if(dist[(10*x)%K]>dist[x]) {
			dist[(10*x)%K]=dist[x];
			todo.push_front((10*x)%K) ;
		}
		if(dist[(x+1)%K]>dist[x]+1) {
			dist[(x+1)%K]=dist[x]+1;
			todo.push_back((x+1)%K);
		}
	}
	cout<<dist[0];
	return 0;
}

