#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;
typedef long long LL;
using Graph = vector<vector<int>>;

static long long INF = (1LL<<62);

class zeroblock{
	public:
		int l, r, len, lenex;
		int lpos, rpos;
		zeroblock(){
			l = 0;     // 左にある1の連続長さ
			r = 0;     // 右にある1の連続長さ
			len = 0;   // 自分の0の長さ
			lenex = 0; // l + r + len
			lpos  = -1; //lenexすべて1にしたときの左端の位置
			rpos  = -1; //lenexすべて1にしたときの右端の位置
		}
		int calc(){
			lenex = l + len + r;
			return lenex;
		}
};

long long N, K;
vector<zeroblock*> B;
string S;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	cin >> S;
	int al = 0, ar = 0, alen = 0;
	zeroblock* b = NULL;
	for(int i=0; i<S.size(); i++){
		if((i == 0 && S[i] == '0') || (i > 0 && S[i-1] == '1' && S[i] == '0')){
			if(B.size() > 0){
				b = B[B.size()-1];
				b->r = ar;
				b->lenex = b->l + b->len + b->r;
				ar = 0;
			}
			b = new zeroblock();
			b->l = al;
			al = 0;
			alen = 0;
		}
		else if(i > 0 && S[i-1] == '0' && S[i] == '1'){
			b->len = alen;
			B.push_back(b);
			alen = 0;
			al = 0;
			ar = 0;
		}

		if(S[i] == '1'){
			ar++;
			al++;
			if(i == S.size()-1 && B.size() > 0){
				zeroblock* p = B[B.size()-1];
				b->r = ar;
			}
		}
		if(S[i] == '0'){
			alen++;
			if(i == S.size()-1){
				b->len = alen;
				B.push_back(b);
			}
		}

	}
	for(int i=0; i<B.size(); i++){
		zeroblock* b = B[i];
		int v = b->calc();
		if(i == 0){
			b->lpos = 0;
			b->rpos = b->lenex - 1;
		}
		else{
			b->lpos = B[i-1]->lpos + B[i-1]->l + B[i-1]->len ;
			b->rpos = b->lpos + b->lenex - 1;
		}
	}

	if(B.size() == 0){
		printf("%lld\n", N);
		return 0;
	}
	if(B.size() == 1 && B[0]->len == N && K >= 1){
		printf("%lld\n", N);
		return 0;
	}

	LL ans = 0;
	for(int s=0; ; s++){
		int e = min(s + (int)K - 1, (int)B.size() - 1);
		int c = B[e]->rpos - B[s]->lpos + 1;
		if(ans < c){
			ans = (LL)c;
		}
		if(e == B.size()-1){
			break;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
