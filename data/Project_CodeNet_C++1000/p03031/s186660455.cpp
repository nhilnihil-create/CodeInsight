#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M;
    vector<int> K;
    vector<vector<int>> S;
    vector<int> P;
    cin >> N >> M;
    for (int m = 0; m < M;m++){
        int k;
        int ss;
        vector<int> s;
        cin >> k;
        K.push_back(k);
        for (int kk = 0; kk < k; kk++)
        {
            cin >> ss;
            s.push_back(ss);
        }
        S.push_back(s);
    }
    for (int i = 0; i < M;i++){
        int p;
        cin >> p;
        P.push_back(p);
    }
    int result = 0;
    for (int bit = 0; bit < (1 << N); bit++)
    {
        bool ok = true;
        for (int m = 0; m < M; m++)
        {
            int count = 0;
            for (int k = 0; k < K[m]; k++)
            {
                if(bit & (1<<S.at(m).at(k)-1)){
                    count++;
                }
            }
            if(count%2 != P.at(m)){
                ok = false;
                break;
            }
        }
        if(ok){
            result++;
        }
    }
    cout << result << "\n";
}
