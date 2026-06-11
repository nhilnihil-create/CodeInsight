#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
typedef vector<int> vi;

int main(){
    int N, M;
    cin >> N >> M;
    vi L(M), R(M);
    
    rep(i, M){
        cin >> L[i] >> R[i];
    }

    int maxl = L[0];
    int minr = R[0];
    rep(i, M){
        maxl = max(maxl, L[i]);
        minr = min(minr, R[i]);
    }

    if(maxl > minr){
        cout << 0 << endl;
    }else{
        cout << minr - maxl + 1 << endl;
    }
    return 0;
}