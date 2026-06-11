#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

constexpr int INF = (1 << 30);

int D, G;
vector<int> p, c;

void input(void){
    cin >> D >> G;
    p.resize(D);
    c.resize(D);
    for (int i = 0; i < D; ++i)
        cin >> p[i] >> c[i];
}

void show(int f){
    for (int i = 0; i < D; ++i)
        cout << ((f & (1 << i)) ? 1 : 0);
}

// コンプリートするか否かのフラグがfであるときに解く最小の問題数
int calc(int f){
    /* cout << "called  ";
    show(f);
    cout << "  :  "; */
    int res = 0;
    int score = 0;
    for (int i = 0; i < D; ++i){
        if (f & (1 << i)){
            res += p[i];
            score += (i + 1) * 100 * p[i] + c[i];
        }
    }
    if (score >= G) return res;
    for (int i = D - 1; i >= 0; --i){
        if (!(f & (1 << i))){
            if (score + (i + 1) * 100 * p[i] < G){
                score += (i + 1) * 100 * p[i];
                res += c[i];
            }
            else{
                int need = G - score;
                int solve = need / ((i + 1) * 100);
                if (need % ((i + 1) * 100)) ++solve;
                return res + solve;
            }
            if (score >= G)
                return res;
        }
    }
    return INF;
}

int main(void){
    input();
    int ans = INF;
    for (int f = 0; f < (1 << D); ++f){
        int tmp = calc(f);
        /* cout << tmp << endl; */
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}