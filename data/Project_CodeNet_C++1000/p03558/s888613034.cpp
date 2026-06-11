#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<string>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<unordered_map>
#include<array>
#include<map>
#include<bitset>
#include<iomanip>
using namespace std;
typedef long long int llint;
typedef long double lldo;
#define mp make_pair
#define mt make_tuple
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define fir first
#define sec second
#define res resize
#define ins insert
#define era erase
//ios::sync_with_stdio(false);
//std::cin.tie(0);
//<< setprecision(20)
//19234567892927;
const int mod=1e9+7;
const llint big=1e15+100;
const long double pai=3.141592653589793238462643383279502884197;
const long double ena=2.71828182845904523536;
const long double eps=1e-7;
template <class T,class U>void mineq(T& a,U b){if(a>b){a=b;}}
template <class T,class U>void maxeq(T& a,U b){if(a<b){a=b;}}
template <class T> void soun(T& ar){sort(ar.begin(),ar.end());ar.erase(unique(ar.begin(),ar.end()),ar.end());}
llint gcd(llint a,llint b){if(a%b==0){return b;}else return gcd(b,a%b);}
llint lcm(llint a,llint b){return a/gcd(a,b)*b;}
int main(void){
	int k;cin>>k;
	vector<int>ans(k,9999999);
	deque<pair<int,int>>que;//tourist
	que.puf(mp(1,1));
	while(-1){
		int di=que.front().fir;
		int now=que.front().sec;
		que.pof();
		if(ans[now]<=di){continue;}
		ans[now]=di;
		if(now==0){cout<<di<<endl;return 0;}
		que.puf(mp(di,(now*10)%k));
		que.pub(mp(di+1,(now+1)%k));
	}
	return 0;
}