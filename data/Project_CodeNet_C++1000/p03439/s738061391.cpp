#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define INF 1e9
#define MAXN 100005
#define MAXM 100005
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define pii pair<int, int>

string S, l ,r, res;
int N, k, ok, ng, mid;

void solve(){
    rep(i, k){
        mid = (ok + ng)/ 2;
        cout << mid << endl;
        cin >> res;
        if(res == "Vacant") exit(1);

        if(mid%2==0)(res==l ? ok : ng)=mid;
        else (res==r ? ok : ng)=mid;
        
    }
}

int main(){
    cin >> N;
    k = 20;

    // 半開区間で管理
    ok = 0, ng = N;

    cout << 0 << endl;
    cin >> l;
    if(l == "Vacant") exit(1);

    cout << N-1 << endl;
    cin >> r;
    if(r == "Vacant") exit(1);

    k -= 2;

    solve();
}
