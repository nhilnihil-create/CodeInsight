#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <iostream>
#include <algorithm>
 
typedef char                SINT8;
typedef unsigned char       UINT8;
typedef short               SINT16;
typedef unsigned short      UINT16;
typedef int                 SINT32;
typedef unsigned int        UINT32;
typedef long long           SINT64;
typedef unsigned long long  UINT64;
typedef double              DOUBLE;
 
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))
#define rep(i,a,b) for(int (i)=int(a);(i)<int(b);(i)++)
 
#define INF 1e9;
#define MOD 1e9+7;
#define INF64 1e18;
 
 
using namespace std;
 
int main() {
 
	SINT64 N = 0;
	SINT64 kazu = 0;
	SINT64 ans = 0;
 
	cin >> N;
 
	vector<SINT32> DATA1(N);
	vector<SINT32> DATA2(N);
	vector<SINT32> clac1(N);
	vector<SINT32> clac2(N);
	vector<SINT64> p(30);
	
	rep(i,0,N) {
		cin >> DATA1[i];
	}
	rep(i,0,N) {
		cin >> DATA2[i];
	}
	rep(i,0,30) {
		p[i] = (SINT64)pow(2,i);
	}
 
	rep(i,1,30) {
 
		SINT64 buf = 0;
		rep(j,0,N) {
			clac1[j] = DATA1[j] % p[i];
			clac2[j] = DATA2[j] % p[i];
		}
		sort(clac2.begin(),clac2.end());
 
		rep(j,0,N) {
			SINT64 A,B,C;
			A = lower_bound(clac2.begin(),clac2.end(), p[i-1]-clac1[j]) - clac2.begin();
			B = lower_bound(clac2.begin(),clac2.end(), p[i]-clac1[j]) - clac2.begin();
			C = lower_bound(clac2.begin(),clac2.end(), p[i-1]+p[i]-clac1[j]) - clac2.begin();
 
			buf += B-A+N-C;
		}
		if ((buf % 2) != 0) {
			ans += p[i-1];
		}
 
	}
 
	cout << ans << endl;
	return 0;
}
 
//	sort(DATA.begin(),DATA.end());
//	sort(DATA.begin(),DATA.end(),std::greater<SINT32>());
//	__gcd(ANS,DATA[i]);
 
//	// DATA.emplace_back(BUF);	//後ろに追加
 
//  DATA.erase(std::unique(DATA.begin(), DATA.end()), DATA.end());	//ソート後に使用
 
//	DATA.insert(DATA.begin() + X, 0);	//X番目の要素に0を挿入
 
 
//	vector<vector<SINT32>> DP(N,vector<SINT32>(3));　//2次元配列
 
/*
	SINT32 M = 3;
	vector<pair<SINT32,SINT32>> DATA2(M);
	for (SINT32 i = 0; i < M; i++) {
		cin >> DATA2[i].first;
		cin >> DATA2[i].second;
	}
	sort(DATA2.begin(),DATA2.end());
	cout << DATA2[0].first << endl;
	cout << DATA2[0].second << endl;
*/
 
// 	vector<pair<int,pair<int,int>>> DATA(M);
//	cin >> DATA[i].first;
//	cin >> DATA[i].second.first;
//	cin >> DATA[i].second.second;
 
 
//		APOSI = lower_bound(ADATA.begin(),ADATA.end(),QDATA[i]) - ADATA.begin(); 
//		BPOSI = lower_bound(BDATA.begin(),BDATA.end(),QDATA[i]) - BDATA.begin();
 
 
/* 文字列回転
	string N;
	cin >> N;
	N = N[N.length()-1] + N.substr(0,N.length()-1);
*/
 
/* SET コンテナ
	set<SINT32> DATA;
	for (SINT32 i = 0; i < N; i++) {
		SINT32 buf;
		cin >> buf;
		DATA.insert(buf);
	}
 
	//全表示
    set<string>::iterator it; //  イテレータを用意
    for(it = DATA.begin(); it != DATA.end(); it++) {
        cout << *it << endl;
    }
 
	//N番目を一部表示
	set<string>::iterator it; //  イテレータを用意
	it = DATA.begin();
	rep (i,0,N) {
		it++;
	}
	cout << *it << endl;
*/
 
/* map
	map<string,SINT32> mp;
	SINT32 N = 0;
	SINT32 mx = 0;
 
	cin >> N;
	for (SINT32 i = 0; i < N; i++) {
		string s;
		cin >> s;
		mp[s]++;
	}
	for(auto it=mp.begin();it!=mp.end();it++) {
		mx=max(mx,it->second);
	}
 
*/