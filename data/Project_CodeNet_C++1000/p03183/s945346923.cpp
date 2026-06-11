#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,int> P;
const LL mod=1000000007;
const LL LINF=1LL<<62;
const LL INF=1<<17;

struct node{
    int w;
    int s;
    int v;
};

int main(){
    int N;cin >> N;
    vector<node> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].w >> v[i].s >> v[i].v;
    }
    vector<LL> dp(20001,-1);
    dp[0] = 0;
    sort(ALL(v),[&](node l,node r){return l.w+l.s<r.w+r.s;});
    for (int i = 0; i < N; i++) {
        for (int j = v[i].s; j >= 0; j--) {
            if(dp[j]==-1) continue;
            dp[j+v[i].w] = max(dp[j+v[i].w],dp[j]+v[i].v);
        }
    }
    cout << *max_element(ALL(dp)) << endl;
    return 0;
}
