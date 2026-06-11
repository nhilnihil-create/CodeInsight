#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
using ll = long long;
int mod = 1000000007;

int solve(int *A);

int main(void){
    int N; cin >> N;
    int cnt[13] = {};
    int D[N]; rep(i, N) cin >> D[i];
    cnt[0]++;
    rep(i, N) cnt[D[i]]++;
    bool kakutei[13] = {};
    vector<int> futei_num;
    bool ok = true;
    // 1から11が1だと不定
    //不定なものについてbit全探索
    kakutei[0] = true;
    if(cnt[12] >= 1) kakutei[12] = true;
    if(cnt[0] >= 2 || cnt[12] >= 2) ok = false;
    for(int i = 1; i <= 11; i++){
        if(cnt[i] >= 3) ok = false;
        else if(cnt[i] == 2) kakutei[i] = true;
        else if(cnt[i] == 1) futei_num.push_back(i);
    }

    int ans = 0;

    int tm[24] = {0};
    if(ok){
        tm[0] = 1;
        if(kakutei[12]) tm[12] = 1;
        for(int i = 1; i <= 11; i++){
            if(kakutei[i]){
                tm[i] = 1;
                tm[24-i] = 1;
            }
        }
        //bit全探索, 不定な時間について
        int lim = pow(2.0, futei_num.size());
        for(int i = 0; i < lim; i++){
            int val = i;
            vector<int> work;
            for(int j = 0; j < futei_num.size(); j++){
                work.push_back(val % 2);
                val /= 2;
            }
            for(int j = 0; j < futei_num.size(); j++){
                if(work[j] == 1) tm[24 - futei_num[j]] = 1;
                else tm[futei_num[j]] = 1;
            }
            int temp = solve(tm);
            if(temp > ans) ans = temp;
            //後始末
            for(int j = 0; j < futei_num.size(); j++){
                if(work[j] == 1) tm[24 - futei_num[j]] = 0;
                else tm[futei_num[j]] = 0;
            }
        }
        cout << ans << endl;
    }
    else cout << 0 << endl;
    return 0;
}

int solve(int *A){
    int s = 24;
    //0が連続する個数の最小を知りたい
    int row = 0;

    //rep(i, 24) cout << A[i] << " "; cout << endl;

    bool allone = true;
    rep(i, 24) if(A[i] != 1) allone = false;
    if(allone) return 1;

    int i = 0;
    while(A[i] == 1) i++;
    for(; i < 24; i++){
        if(A[i] == 0) row++;
        else{
            if(row < s) s = row;
            while(i < 24 && A[i] == 1) i++;
            row = 1;
        }
    }
    if(row > 0 && row < s) s = row;

    //1の連続も検出したいよねぇ
    if(A[23] == 1) s = 0;
    for(int i = 1; i <= 22; i++) if(A[i] == 1 && A[i-1] == 1) s = 0;
    return s+1;
}