#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int64_t N,K;
    string S;
    char last;
    int rnpos = 0;
    int cnt = 0;
    int64_t sum = 0;
    int rpos,lpos;
    int64_t maxsum = 0;

    cin >> N >> K >> S;

    // rnrnrnrnr の配列で nがkまで rの連続を作ることが出来る
    
    vector<vector<int>> rn(2);
    vector<int> *p = &rn[0];
    if(S[0] == '0'){
        (*p).push_back(0);
        p = &rn[1];
        rnpos = 1;
    } else {
        p = &rn[0];
        rnpos = 0;
    }
    
    last = S[0];
    for(int i=0;i<S.size();i++) {
        if(last != S[i]) {
            (*p).push_back(cnt);
            cnt = 0;
            rnpos++;
            p = &rn[rnpos%2];
        }

        cnt++;
        last = S[i];
    }

    (*p).push_back(cnt);
    if(rn[1].size() <= K) {
        cout << N << endl;
        return 0;
    }

    // しゃくとり法
    vector<int> *pleft;
    vector<int> *pright;
    
    // 直立をK(倒立をK+1)まで加算して直立/倒立の組を一つずつ加算、減算して最大を取得
    for(int i=0;i<K;i++) {
        sum += rn[0][i] + rn[1][i];
    }

    if(rn[0].size() > K) {
        sum += rn[0][K];
    }

    maxsum = sum;

    lpos = K;
    rpos = 0;
    while(1) {
        if(rn[1].size() > lpos) {
            // 直立があれば
            sum += rn[1][lpos];

            // 減算は両方
            sum -= rn[0][rpos];            
            sum -= rn[1][rpos];
            if(maxsum < sum) {
                maxsum = sum;
            }
        } else {
            break;
        }

        lpos++;
        if(rn[0].size() > lpos) {
            sum += rn[0][lpos];
            if(maxsum < sum) {
                maxsum = sum;
            }
        } else {
            break;
        }

        rpos++;
    }
        
    cout  << maxsum << endl;

    return 0;
}
