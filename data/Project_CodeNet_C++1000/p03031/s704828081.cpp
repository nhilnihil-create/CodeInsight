#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main(void){
    int N, M;
    cin >> N >> M;
    vector<int> k(M, 0);
    vector<int> p(M, 0);
    vector<vector<int>> s(M);
    for(int i{0}; i<M; ++i){
        cin >> k.at(i);
        s.at(i) = vector<int>(k.at(i), 0);
        for(int j{0}; j<k.at(i); ++j){
            cin >> s.at(i).at(j);
        }
    }
    for(int i{0}; i<M; ++i){
        cin >> p.at(i);
    }

    int n{0};
    for(int bit{0}; bit<(1<<N); ++bit){
        bool result{true};
        for(int i{0}; i<M; ++i){
            int sum{0};
            for(int j{0}; j<k.at(i); ++j){
                if(bit & (1 << (s.at(i).at(j)-1))){
                    ++sum;
                }
            }
            if(sum%2 != p.at(i)){
                result = false;
                break;
            }
        }
        if(result){
            ++n;
        }

    }

    cout << n << endl;
}
