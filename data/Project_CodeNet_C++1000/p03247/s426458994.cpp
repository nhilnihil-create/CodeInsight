#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
 
#define mod 1000000007
#define FOR(x,to) for(int x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define long long long
inline int rei(){int x;cin>>x;return x;}
inline long rel(){long x;cin>>x;return x;}
inline string res(){string x;cin>>x;return x;}
//------------------------------------------------------- 
long X[10000];
long Y[10000];
void Calc(){
	int N = rei();
	for(int i=0;i<N;i++){
		X[i] = rel();
		Y[i] = rel();
	}
	for(int i=1;i<N;i++){
		if((X[i] + Y[i] + 1000000000000) % 2 != (X[i-1] + Y[i-1] + 1000000000000) % 2){
			cout << -1 << endl;
			return;
		}
	}
	long sum = 0;
	if((X[0] + Y[0] + 1000000000000) % 2 == 0){
		cout << 33 << endl;
		for(int i=0;i<32;i++){
			cout << (((long)(1)) << i) << " ";
			sum += (((long)(1)) << i);
		}
		cout << 1 << endl;
		sum++;
		for(int i=0;i<N;i++){
			long plus = X[i] + Y[i];
			long minus = X[i] - Y[i];
			plus = sum - plus;
			minus = sum - minus;
			plus /= 2;
			minus /= 2;
			for(int j=0;j<32;j++){
				bool p = (plus & (((long)(1)) << j)) == 0;
				bool m = (minus & (((long)(1)) << j)) == 0;
				if(p && m){
					cout << 'R';
				}
				if(p && !m){
					cout << 'U';
				}
				if(!p && m){
					cout << 'D';
				}
				if(!p && !m){
					cout << 'L';
				}
			}
			cout << 'R' << endl;
		}
	}
	else{
		cout << 32 << endl;
		for(int i=0;i<31;i++){
			cout << (((long)(1)) << i) << " ";
			sum += (((long)(1)) << i);
		}
		cout << (((long)(1)) << 31) << endl;
		sum += (((long)(1)) << 31);
		for(int i=0;i<N;i++){
			long plus = X[i] + Y[i];
			long minus = X[i] - Y[i];
			plus = sum - plus;
			minus = sum - minus;
			plus /= 2;
			minus /= 2;
			for(int j=0;j<32;j++){
				bool p = (plus & (((long)(1)) << j)) == 0;
				bool m = (minus & (((long)(1)) << j)) == 0;
				if(p && m){
					cout << 'R';
				}
				if(p && !m){
					cout << 'U';
				}
				if(!p && m){
					cout << 'D';
				}
				if(!p && !m){
					cout << 'L';
				}
			}
			cout << endl;
		}
	}
}
int main(int argc,char** argv){
	ios::sync_with_stdio(false), cin.tie(0);
	cout.tie(0); Calc(); return 0;
}