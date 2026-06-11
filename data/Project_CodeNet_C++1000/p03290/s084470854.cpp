#include <bits/stdc++.h>
using namespace std;

/*
ボーナススコアがない場合は点数の大きい問題から解いていく貪欲法でOK
ボーナススコアを得る問題の組み合わせについて全探索する
*/

int main() {
    long D, G; cin >> D >>G;

    vector<long> P(D), C(D);

    for (int i = 0; i < D; i++)
    {
        cin >> P[i] >> C[i];
    }

    int min_num = 1e9;
    for (int tmp = 0; tmp < (1 << D); tmp++)
    {
        bitset<10> s(tmp);
        long score = 0;
        int num = 0;
        for (int i = 0; i < D; i++)
        {
            if (s.test(i)) {
                score += 100 * (i + 1) * P[i] + C[i];
                num += P[i];
            }
        }

        if (score < G) {

            for (int i = D-1; i >= 0; i--) {
                if (s.test(i)) {
                    continue;
                }
                else
                {
                    for (int j = 0; j < P[i]; j++)
                    {
                        if (score >= G)
                        {
                            continue;
                        }
                        
                        num++;
                        score += 100 * (i + 1);
                    }
                }
                
            }
        }

        if (score >= G) {
            min_num = min(num, min_num);
        }
    }
    cout << min_num << endl;
    

}