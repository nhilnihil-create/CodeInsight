#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
using namespace std;
typedef vector<int> vi;

bool exist(int x, vi A){
    bool a = false;
    rep(i, A.size()){
        if(A[i] == x) a = true;
    }
    return a;
}

int main(){
    int N, M, X;
    cin >> N >> M >> X;
    vi A(M);
    rep(i, M) cin >> A[i];

    int cost1 = 0, cost2 = 0;

    for(int i = 0; i < X; i++){
        if(exist(i, A)) cost1++;
    }

    for(int i = X+1; i < N; i++){
        if(exist(i, A)) cost2++;
    }


    int cost = min(cost1, cost2);

    cout << cost << endl;

    return 0;
}