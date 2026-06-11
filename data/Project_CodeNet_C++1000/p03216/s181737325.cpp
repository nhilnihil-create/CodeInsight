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
int dx[4]={0,0,1,1};
int dy[4]={0,1,0,1};
const int SIZE=1000050;
//ここまでテンプレ
int main(){
	int N;
	cin>>N;
	string S;
	cin>>S;
	int Q;
	cin>>Q;
	while(Q--){
		int k;
		cin>>k;
		ll ans=0;
		ll d=0,m=0,dm=0;
		//Sを前から見る
		for(int i=0;i<N;i++){
			if(i-k>=0 && S[i-k]=='D'){
				d--;
				dm-=m;
			}
			if(S[i]=='D')
				d++;
			if(S[i]=='M'){
				dm+=d;
				m++;
			}
			if(i-k>=0 && S[i-k]=='M')
				m--;
			if(S[i]=='C')
				ans+=dm;

			//cout<<S[i]<<" "<<d<<" "<<m<<" "<<dm<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}