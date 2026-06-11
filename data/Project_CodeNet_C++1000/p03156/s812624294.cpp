#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int MOD = 1000000007;
typedef long long ll;


int main(){
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> P(N);
    rep(i, N) cin >> P[i];
    int s = 0, m = 0, l = 0;
    rep(i, N){
        if(P[i] <= A) s++;
        else if(P[i] <= B) m++;
        else l++;
    }
    cout << min(s, min(m, l)) << endl;
    return 0;
}
