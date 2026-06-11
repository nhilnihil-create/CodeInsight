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
#include <unordered_map>
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
#define eb emplace_back
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pint;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pint> vpint;
int dx[8]={0,0,-1,1,1,1,-1,-1};
int dy[8]={-1,1,0,0,1,-1,1,-1};
const int SIZE=100050;
//ここまでテンプレ
int main(){
	int N;
	cin>>N;
	vint X,Y;
	for(int i=0;i<N;i++){
		int x,y;
		cin>>x>>y;
		X.pb(x);
		Y.pb(y);
	}
	//x+yが全部同じじゃないなら無理
	bool flag=abs(X[0]+Y[0])%2;
	for(int i=0;i<N;i++){
		if(abs(X[i]+Y[i])%2!=flag){
			cout<<-1<<endl;
			return 0;
		}
	}
	//V=X+Y,W=X-Y
	vint V,W;
	for(int i=0;i<N;i++){
		V.pb(X[i]+Y[i]);
		W.pb(X[i]-Y[i]);
	}
	int arms=31;
	vint A={1};
	if(!flag)
		A.pb(1);
	for(int i=1;i<arms;i++)
		A.pb(A.back()*2);
	reverse(A.begin(),A.end());
	cout<<A.size()<<endl;
	for(int i=0;i<A.size();i++)
		cout<<A[i]<<(i==A.size()-1?'\n':' ');
	for(int i=0;i<N;i++){
		int v=0,w=0;
		for(int j=0;j<A.size();j++){
			if(v<=V[i] && w<=W[i]){
				cout<<'R';
				v+=A[j],w+=A[j];
			}
			else if(v<=V[i] && w>W[i]){
				cout<<'U';
				v+=A[j],w-=A[j];
			}
			else if(v>V[i] && w<=W[i]){
				cout<<'D';
				v-=A[j],w+=A[j];
			}
			else{
				cout<<'L';
				v-=A[j],w-=A[j];
			}
		}
		cout<<endl;
	}
	return 0;
}