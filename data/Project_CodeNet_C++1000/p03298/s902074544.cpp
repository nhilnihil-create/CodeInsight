#include<string>
#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main(){
    int N;
    string S;
    cin >> N;
    cin >> S;
    string halfS[2];
    halfS[0] = S.substr(0, N);
    halfS[1] = S.substr(N, N);
    reverse(halfS[1].begin(), halfS[1].end());
    unordered_map<string, long long> cnt[2];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < (1 << N); j++){
            string tmp[2];
            tmp[0].reserve(N);
            tmp[1].reserve(N);
            for(int k = 0; k < N; k++){
                if( j & (1 << k)){
                    tmp[1].push_back(halfS[i][k]);
                }else{
                    tmp[0].push_back(halfS[i][k]);
                }
            }
            cnt[i][tmp[0] + "," + tmp[1]]++;
        }
    }
    long long ans = 0;
    for(unordered_map<string, long long>::iterator it = cnt[0].begin(); it != cnt[0].end(); it++){
        ans += cnt[0][it->first] * cnt[1][it->first];
    }
    cout << ans << endl;
}