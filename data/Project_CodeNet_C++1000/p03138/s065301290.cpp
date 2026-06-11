#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
typedef long long ll;

const int INF = 1e9+7;

using ipair = pair<int, int>;

bool operator>(const ipair a,const ipair b){return a.first > b.first;}

ll N, K;
vector<ll> A;
vector<ll> cnt(64);
vector<ll> original_pattern(64);
ll judge;
string K_str;



int main(){
    cin >> N >> K;

    // original count
    rep(i, 64){
        if(K>>i & 1) original_pattern[i]=1;
    }
    reverse(original_pattern.begin(), original_pattern.end());


    A.resize(N);
    rep(i, N) cin >> A[i];

    // cnt
    for(ll num: A){
        rep(i, 64){
            if(num>>i & 1) cnt[i]++;
        }
    }
    reverse(cnt.begin(), cnt.end());

    judge = N/2 + N%2;

    vector<ll> ans_pattern(64);

    bool flipped = false;
    rep(i, 64){
        int one_cnt = cnt[i];
        int zero_cnt = N - cnt[i];
        if(zero_cnt >= judge){
            // 0 -> 1
            if(original_pattern[i]==0){
                if(!flipped){
                    ans_pattern[i] = 0;
                }else{
                    ans_pattern[i] = 1;
                }
            }else{
                ans_pattern[i] = 1;
            }
        }else{
            // 1 -> 0
            if(original_pattern[i]==1 && !flipped) flipped = true;
            ans_pattern[i] = 0;
        }
    }

    // rep(i, 64) cout << cnt[i] << " ";
    // rep(i, 64) cout << original_pattern[i] << " ";
    // rep(i, 64) cout << ans_pattern[i] << " ";
    // cout << endl;

    reverse(ans_pattern.begin(), ans_pattern.end());
    reverse(cnt.begin(), cnt.end());

    ll ans = 0;
    ll mul = 1;
    rep(i, 64){
        // cout << "==" << endl;
        // cout << "i:" << i << endl; 
        if(ans_pattern[i] == 1){
            // cout << "added:" << (N - cnt[i])*mul << endl;
            ans += (N - cnt[i])*mul;
        }else{
            // cout << "added:" << cnt[i]*mul << endl;
            ans += cnt[i]*mul;
        }
        mul *= 2;
    }

    cout << ans << endl;

    return 0;
}