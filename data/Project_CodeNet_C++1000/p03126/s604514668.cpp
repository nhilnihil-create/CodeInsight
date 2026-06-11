/**************************
*                         *
*  Nothing Is Impossible  *
*                         *
**************************/
#include <algorithm>
#include <pthread.h>
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string>
#include <vector>
#include <thread>
#include <math.h>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <set>
#include <map>
#define GetRand(Min, Max) ((rand()%(int)(((Max) + 1)-(Min))) + (Min))
#define Rep(i, min, max) for(int i = min; i < max; ++i)
#define PB push_back
#define MP make_pair
typedef long long ll;
typedef long double ld;
using namespace std;

void Solve(){
	int n,M;	cin >> n >> M;
	map <int,int> m;
	int x,k;
	Rep(i,0,n){
		cin >> x;
		Rep(i,0,x){
			cin >> k;
			if(!m[k]){
				m[k] = 0;
			}
			m[k]++;
		}
	}
	int ans = 0;
	for(auto c : m){
		if(c.second == n){
			ans++;
		}
	}
	cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}