#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
#define int long long
#define REP(i,n) for(int i = 0;i < (int)(n);i++)
#define FOR(i,s,n) for(int i = s;i < (int)n;i++)
#define RREP(i,n) for(int i = (int)n-1;i >= 0;i--)
#define RFOR(i,s,n) for(int i = (int)n-1;i >= s;i--)
template<class T>inline bool CHMAX(T&a,T b){if(a<b){a = b;return true;}return false;}
template<class T>inline bool CHMIN(T&a,T b){if(a>b){a = b;return true;}return false;}

signed main(){
	int N;
	cin >> N;
	vector<int>d(N);
	REP(i,N)cin>>d[i];
	sort(d.begin(),d.end());
	RFOR(i,1,13){
		int prev = 0;
		vector<int>cnt;
		cnt.push_back(0);
		REP(j,N){
			if(d[j]-prev<i){
				cnt.push_back(24-d[j]);
			}else{
				cnt.push_back(d[j]);
				prev=d[j];
			}
		}
		sort(cnt.begin(),cnt.end());
		int flg = 24-cnt.back()>=i;
		REP(j,N+1){
			FOR(k,j+1,N+1){
				if(abs(cnt[k]-cnt[j])<i)flg=0;
			}
		}
		if(flg){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<0<<endl;
}