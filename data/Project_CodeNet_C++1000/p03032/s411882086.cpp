// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;

int N, K;

int sum(vector<int> &V, int i, int j, int count){
    vector<int> T;
    for(int k = 0; k < i; k++) T.push_back(V[k]);
    for(int k = j; k < N; k++) T.push_back(V[k]);
    sort(all(T));

    int index = 0, T_sum = 0;
    while(count > 0 && index < T.size() && T[index] < 0 ){
        index++;
        count--;
    }

    while(index < T.size()){
        T_sum += T[index];
        index++;
    }

    return T_sum;
}

int main(){
    cin >> N >> K;
    vector<int> V(N);
    rep(i, N) cin >> V[i];

    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = i; j <= N; j++){
            int s = N - (j - i);
            int c = K - s;
            if(c < 0) continue;
            ans = max(ans, sum(V, i, j, c));
        }
    }

    cout << ans << endl;

}