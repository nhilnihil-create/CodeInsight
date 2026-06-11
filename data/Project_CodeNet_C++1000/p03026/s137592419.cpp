//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/m-solutions2019/tasks/m_solutions2019_d

//参考：
//https://trsing.hatenablog.com/entry/2019/06/03/153201#f-b03a08e5

//取りうる最大値を考えた上で、それを達成できるのはどういう時か考える

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

int N;
vector<vector<int>> adj;
priority_queue<int> C;
int A[10000],B[10000];

LL ans_score = 0;
vector<LL> ans;

void solve(){
	queue<int> q;
	q.push(1);
	ans[1] = C.top();C.pop();
	while(!q.empty()){
		int now = q.front();q.pop();
		for(int next : adj[now]){
			if(ans[next]==-1){
				ans[next] = C.top();C.pop();
				q.push(next);
			}
		}
	}
	for(int i=0;i<N-1;i++){
		ans_score += min(ans[A[i]],ans[B[i]]);
	}
}
 
int main(){
    cin >> N;
    ans = vector<LL>(N+1,-1);
    adj = vector<vector<int>>(N+1);
    for(int i=0;i<N-1;i++){
    	int a,b;cin >> a >> b;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    	A[i] = a;
    	B[i] = b;
    }
    for(int i=0;i<N;i++){
    	int c;cin >> c;
    	C.push(c);
    }
 
    solve();

    cout << ans_score << endl;
    for(int i=1;i<=N;i++)cout << ans[i] << " ";
    	cout << endl;
    return 0;
}