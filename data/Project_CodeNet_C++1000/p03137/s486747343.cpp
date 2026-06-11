#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

int main(){
    int N, M;
    cin >> N >> M;
    vector<LL> X(M);
    REP(i,M)cin>>X[i];

    if(N >= M){
        cout << 0 << endl;
        return 0;
    }

    sort(X.begin(), X.end());

    vector<LL> dist(M-1);
    LL sum = 0;
    REP(i,M-1){
        dist[i] = abs(X[i+1] - X[i]);
        sum += dist[i];
    }

    sort(dist.begin(), dist.end(), greater<LL>());

    REP(i,N-1){
        sum -= dist[i];
    }

    cout << sum << endl;
    return 0;

    


}