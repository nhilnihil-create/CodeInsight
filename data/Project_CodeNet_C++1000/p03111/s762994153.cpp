#include <iostream>
#include <map>
#include <vector>
#define int long long
typedef long long ll;
using namespace std;

ll N, A, B, C, Len[8], minmp=10000000000;

void dfs(ll id, ll v[8]){
    if(id==N-1) {
        ll abc[4]={0}, abclen[4]={0};
        for(int i=0;i<=id;i++) {
            abc[v[i]]++;
            abclen[v[i]] += Len[i];
        }
        if(abc[1]*abc[2]*abc[3]==0) return;
        ll mp = (abc[1]+abc[2]+abc[3]-3)*10;
        mp += abs(A-abclen[1]) + abs(B-abclen[2]) + abs(C-abclen[3]);
        minmp = min(mp, minmp);
        return;
    }
    v[id+1] = 0;
    dfs(id+1, v);
    v[id+1] = 1;
    dfs(id+1, v);
    v[id+1] = 2;
    dfs(id+1, v);
    v[id+1] = 3;
    dfs(id+1, v);
}

signed main(){
    cin >> N >> A >> B >> C;
    for(int i=0;i<N;i++) cin >> Len[i];
    ll vinit[8]={0};
    dfs(-1, vinit);
    cout << minmp << endl;
    return 0;
}