#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;


int main(){
    int N, K; cin >> N >> K;
    string S; cin >> S;

    char current = S[0];

    vector<int> compress;
    int count = 0;
    rep(i,N){
        if (current == S[i]){
            count++;
        }
        else{
            compress.push_back(count);
            count = 1;
            current = S[i];
        }
    }
    compress.push_back(count);

    // 累積和を取得
    vector<int> cum(compress.size()+1,0);
    rep(i,compress.size()){
        cum[i+1] = cum[i] + compress[i];
    }

    int now = 0;
    if (S[0] == '1') now++;
    
    int ans = 0;
    for (int left = 0; left < cum.size(); left++){
        int tmp = 0;
        int add = 2*K;
        if (now == 1) add++;
        
        int right = min(left+add, (int)cum.size()-1);
        tmp = cum[right] - cum[left];
        ans = max(ans, tmp);
        
        // 0と1を切り替える
        now = 1 - now;
    }

    cout << ans << endl;

}