#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000007;
int ans = INF;
vector<int> l;
int A,B,C;
int N;
void rec(int a,int b,int c,int n,int cnt_a,int cnt_b,int cnt_c){
	if(n == N){
		if(a > 0 && b > 0 && c > 0)ans = min(ans,10 * (cnt_a+cnt_b+cnt_c-3) + abs(A-a)+abs(B-b)+abs(C-c));
		return;
	}
	rec(a+l[n],b,c,n+1,cnt_a+1,cnt_b,cnt_c);
	rec(a,b+l[n],c,n+1,cnt_a,cnt_b+1,cnt_c);
	rec(a,b,c+l[n],n+1,cnt_a,cnt_b,cnt_c+1);
	rec(a,b,c,n+1,cnt_a,cnt_b,cnt_c);//どれにも合成しない場合.
}
int main(){
	cin >> N >> A >> B >> C;
	l.resize(N);
	for(int i = 0;i < N;i++)cin >> l[i];
	rec(0,0,0,0,0,0,0);

	cout << ans << endl;
}
