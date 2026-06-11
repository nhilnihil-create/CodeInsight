// Author : Rifayat Samee (Sanzee)
// Problem :
// Algorithm:

/*

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxval 2*10005
struct Node{
    int w;
    int s;
    ll v;
    bool operator<(const Node &b)const{
        return b.w + b.s > w + s;
    }
};


int main(){

	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
    int n;
    scanf("%d",&n);
    vector<Node>B(n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&B[i].w,&B[i].s,&B[i].v);
    }
    sort(B.begin(),B.end());
    vector<ll>P(maxval+1,0);
    for(int i=0;i<n;i++){
        vector<ll>dp(maxval+1);
        dp = P;
        for(int w=0;w<=B[i].s;w++){
            dp[w+B[i].w] = max(P[w+B[i].w],P[w]+B[i].v);
        }
        P = dp;
    }
    ll res = 0;
    for(int w = 0; w<=maxval;w++) res = max(res,P[w]);
    printf("%lld\n",res);
	return 0;
}
