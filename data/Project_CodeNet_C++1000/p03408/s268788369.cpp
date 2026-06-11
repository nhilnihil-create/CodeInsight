#include <bits/stdc++.h>
using namespace std;

int main(){

    int N, M;
    map<string, int> blue;
    map<string, int> red;
    cin >> N;
    for (int i=0; i<N; i++){
        string buf;
        cin >> buf;
        blue[buf]++;
    }
    cin >> M;
    for (int i=0; i<M; i++){
        string buf;
        cin >> buf;
        red[buf]++;
    }

    int ans = 0, temp = 0;
    for (auto bp: blue){
        auto bkey = bp.first;
        auto bvalue = bp.second;
        
        temp += bvalue;

        for (auto rp: red){
            auto rkey = rp.first;
            auto rvalue = rp.second;

            if (bkey == rkey) temp -= rvalue;
        }
        ans = max(ans, temp);
        temp = 0;
    }

    cout << ans << endl;
    return 0;
}