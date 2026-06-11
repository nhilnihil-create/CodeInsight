#include <bits/stdc++.h>
using namespace std;
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
    int N, M;

    cin >> N;
    vector<string> s_N(N);
    rep2(i, 0, N) cin >> s_N.at(i);

    cin >> M;
    vector<string> s_M(M);
    rep2(i, 0, M) cin >> s_M.at(i);

    vector<string> list(0);
    list.push_back(s_N.at(0));

    int check;

    rep2(i, 1, N){
        check = 0;

        rep2(j, 1, list.size()){
            if(s_N.at(i) == list.at(j)){
                check = 1;
                break;
            }
        }

        if(check == 0) list.push_back(s_N.at(i));
    }


    int score, max_score = 0;
    rep2(i, 0, list.size()){
        score = 0;
        rep2(j, 0, N){
            if(list.at(i) == s_N.at(j)) score++;
        }
        rep2(j, 0, M){
            if(list.at(i) == s_M.at(j)) score--;
        }

        if(max_score < score) max_score = score;
    }

    cout << max_score << endl;
}
