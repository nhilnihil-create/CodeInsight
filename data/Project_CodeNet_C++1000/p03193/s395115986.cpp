#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <algorithm>
#include <functional>
#include <numeric>
#include <list> 
#include <cmath>
#include <stdio.h>

using namespace std;
using ll = long long;
#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define ALL(x) x.begin(),x.end()
#define INF (1e9)

typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> P;

#define CAPITAL
void Yes(bool ex=true){
	#ifdef CAPITAL
	cout<<"YES"<<endl;
	#else
	cout<<"Yes"<<endl;
	#endif
	if(ex)exit(0);
}
void No(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<endl;
	#else
	cout<<"No"<<endl;
	#endif
	if(ex)exit(0);
}

int main() {
    int N, H, W;
    cin >> N >> H >> W;
    int ans = 0;
    REP(i, N) {
        int a, b;
        cin >> a >> b;
        if (a >= H && b >= W) {
            ans += 1;
        }
    }
    printf("%d", ans);
}