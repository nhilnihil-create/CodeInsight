#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main(void){
    int N, M;
    cin >> N >> M;
    vector<int> k(M, 0);
    vector<vector<int>> s(M);
    vector<int> p(M, 0);

    // load k and s
    for(int i{0}; i<M; ++i){
        cin >> k.at(i);
        s.at(i) = vector<int>(k.at(i), 0);
        for(int j{0}; j<k.at(i); ++j){
            cin >> s.at(i).at(j);
        }
    }

    // load p
    for(int i{0}; i<M; ++i){
        cin >> p.at(i);
    }

    int n{0};
    for(int biti{0}; biti<(1<<N); ++biti){
        bitset<10> bit(biti);
        bool result{true};
        for(int i{0}; i<M; ++i){
            int sum{0};
            for(int j{0}; j<k.at(i); ++j){
                if(bit.test(s.at(i).at(j)-1)){
                    ++sum;
                }
            }
            if(sum%2 != p.at(i)){
                result = false;
                //break;
            }
        }
        if(result){
            ++n;
        }

    }

    cout << n << endl;
}
