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
#include<array>
#include<map>
#include<iomanip>
#include<assert.h>
#include<bitset>
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
const llint mod=1e9+7;
const llint big=2.19e18+1;
const long double pai=3.141592653589793238462643383279502884197;
const long double eps=1e-15;
template <class T,class U>void mineq(T& a,U b){if(a>b){a=b;}}
template <class T,class U>void maxeq(T& a,U b){if(a<b){a=b;}}
llint gcd(llint a,llint b){if(a%b==0){return b;}else return gcd(b,a%b);}
llint lcm(llint a,llint b){return a/gcd(a,b)*b;}
template<class T> void SO(T& ve){sort(ve.begin(),ve.end());}
template<class T> void REV(T& ve){reverse(ve.begin(),ve.end());}
template<class T>llint LBI(vector<T>&ar,T in){return lower_bound(ar.begin(),ar.end(),in)-ar.begin();}
template<class T>llint UBI(vector<T>&ar,T in){return upper_bound(ar.begin(),ar.end(),in)-ar.begin();}
int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	llint i,k;cin>>k;
	//まずは観測
	//1~9
	//表10～99
	//そのあとは9999...
	vector<pair<llint,int>>snuke;
	for(i=1;i<=9;i++){snuke.pub(mp((llint)i,i));}
	for(i=1;i<=9;i++){snuke.pub(mp((llint)i*10+9,i+9));}
	llint kake=1;
	for(int h=0;h<14;h++){
		//hはそのあとの9の数
		for(i=100;i<=999;i++){
			llint deg=(i+1)*kake -1;
			llint gg=deg;
			int sum=0;
			while(gg>0){sum+=gg%10;gg/=10;}
			while(snuke.back().fir*sum>deg*snuke.back().sec){snuke.pob();}
			snuke.pub(mp(deg,sum));
		}
		kake*=10;
	}
	for(i=0;i<k;i++){cout<<snuke[i].fir<<endl;}
	return 0;
}