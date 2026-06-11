#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int C[100];
int P[100];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int d,g;cin>>d>>g;
    for(int i=1;i<=d;i++){
        cin>>P[i]>>C[i];
    }
    int ans = 1e9;
    // 1問で完結する場合
    // for(int i=1; i<=d; i++){
    //     int t = (g + (100*i -1)) / (100*i);
    //     if(C[i]>t) chmin(ans, t);
    // }

    for(int bit = 0; bit<(1<<d); bit++){
        int t_score = 0;
        int p_count = 0;
        int chosen[100] = {0};
        for(int i=0; i<d; i++){
            if(bit & (1<<i)){ // 完答するやつ
                int index = i+1;
                chosen[index]=1;
                t_score += ((index*100 * P[index]) + C[index]);
                p_count += P[index];
            }
        }
        // 超えていなかった部分の帳尻合わせ
        if(t_score < g){
            int rem = g-t_score;
            for(int i=1; i<=d;i++){
                if(chosen[i] || P[i]==1) continue;
                int t = (rem + (100*i -1)) / (100*i);
                if(P[i]>t) chmin(ans, p_count+t);
            }
        } else {
            chmin(ans, p_count);
        }
    }
    cout<<ans<<endl;
    return 0;
}