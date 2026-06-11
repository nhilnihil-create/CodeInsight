#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <utility>
#include <tuple>
#include <cctype>
#include <bitset>
#include <complex>
#include <cmath>
#include <array>
using namespace std;
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
#define MOD 1000000007
#define mp make_pair
#define mt make_tuple
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pint;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
int dx[8]={0,0,-1,1,1,1,-1,-1};
int dy[8]={-1,1,0,0,1,-1,1,-1};
const int SIZE=200050;
//ここまでテンプレ
int main(){
	int H,W,N;
	cin>>H>>W>>N;
	//それぞれの行について、もっとも左にあるブロックの位置
	priority_queue<int,vint,greater<int>> que[SIZE];
	for(int i=0;i<N;i++){
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		que[x].push(y);
	}
	//到達可能な列の中で最も右のものを持ちながら下に下がっていく
	int R=0,ans=0;
	for(int i=1;i<H;i++){
		ans++;
		if(que[i].empty() || que[i].top()>R+1){
			R++;
		}
		else if(que[i].top()<=R){
			cout<<ans<<endl;
			return 0;
		}
	}
	cout<<H<<endl;
	return 0;
}