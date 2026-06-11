#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    // input
    int D, G;
    cin >> D >> G;
    vector<ll> p(D), c(D);
    for (int i = 0; i < D; i++)
    {
        cin >> p[i] >> c[i];
    }
    

    // bit全探索
    int ans = 1000;
    for (int bit = 1; bit < (1 << D); bit++)
    {
        vector<int> solved;
        for (int i = 0; i < D; i++)
        {
            if (bit & (1 << i)){
                solved.push_back(i); //0-indexed
            }
        }

        // フラグ立ってる問題を全部解いた場合
        ll max_score = 0;
        int tmp_ans = 0;
        for (int i = 0; i < solved.size(); i++)
        {
            max_score += (100 * (solved[i] + 1) * p[solved[i]]) + c[solved[i]];
            tmp_ans += p[solved[i]];
        }
        if (max_score < G)
        {
            continue;
        }
        if (ans > tmp_ans)
        {
            ans = tmp_ans;
        }
        

        // 特定の点数の問題を減らしていく
        for (int i = 0; i < solved.size(); i++)
        {
            ll tmp_score = max_score;
            int tmp_tmp_ans = tmp_ans;
            tmp_score -= c[solved[i]];
            for (int j = 0; j < p[solved[i]]; j++)
            {
                tmp_score -= 100 * (solved[i] + 1);
                tmp_tmp_ans--;
                if (tmp_score < G)
                {
                    break;
                }
                if (ans > tmp_tmp_ans)
                {
                    ans = tmp_tmp_ans;
                }
            }            
        }
    }

    cout << ans << endl;
    return 0;
}
