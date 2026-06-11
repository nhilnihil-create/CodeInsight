#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    vector<int> a(N);
    vector<int> b(M);
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < M; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    bool flg = false;
    if(X >= Y){
        cout << "War" << endl;
        return 0;
    }
    for(int i = X+1; i <=Y; i++){
        if((a[N-1] < i) && (b[0] >= i)) flg = true;

    }

    if(flg) cout << "No War" << endl;
    else cout << "War" << endl;

    return 0;
}