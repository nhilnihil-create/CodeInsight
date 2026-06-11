#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <vector>
//#define ivorysi
#define MAXN 100005
#define eps 1e-7
#define mo 974711
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long int64;
typedef unsigned int u32;
typedef double db;
int64 A,B;
int Q;
int64 calc(int64 X,int64 MID) {
	int64 s = MID,t = X - MID + 2;
	if(s >= A) ++s;
	if(t <= B) --t;
	return  s * t;
}
int64 get_Max(int64 X,int64 L,int64 R) {
    while(R - L + 1 >= 3) {
    	int64 K = (R - L + 1) / 3;
    	int64 LB = L + K,RB = R - K;
    	if(calc(X,LB) < calc(X,RB)) L = LB;
    	else R = RB;
    }
    int64 ans = 0;
    for(int64 i = L ; i <= R ; ++i) ans = max(ans,calc(X,i));
    return ans;
}
int64 check(int64 MID) {
	int64 res = 0;
	res = max(get_Max(MID,1,A - 1),res);
	res = max(get_Max(MID,MID - A + 2,MID),res);
	res = max(get_Max(MID,1,B - 1),res);
	res = max(get_Max(MID,MID - B + 2,MID),res);
	res = max(get_Max(MID,A,B),res);
	res = max(get_Max(MID,A,MID - B + 2),res);
	res = max(get_Max(MID,B,MID - A + 2),res);
	return res;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    scanf("%d",&Q);
    while(Q--) {
	    scanf("%lld%lld",&A,&B);
	    if(A > B) swap(A,B);
	    int64 P = A * B;
	    int64 L = 0,R = (A + B);
	    while(L < R) {
	        int64 MID = (L + R + 1) >> 1;
	        if(check(MID) < P) L = MID;
	        else R = MID - 1;
	    }
	    printf("%lld\n",L);
    }
}