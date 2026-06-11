// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;

int main(){
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    S = ' ' + S;

    vector<int> index;

    for(int i = 1; i < S.size(); i++){
        if(S[i] != S[i - 1]) index.push_back(i);
    }

    int ans = 0;
    for(int i = 1; i <= index.size(); i++){
        int tmp1 = index[i - 1];
        
        int j = i + 2 * K;
        if(S[tmp1] == '1') j += 1;

        int tmp2;
        if(j > index.size()) tmp2 = N + 1;
        else tmp2 = index[j - 1];
        ans = max(ans, tmp2 - tmp1);
    }

    cout << ans << endl;

}