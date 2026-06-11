#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    long long N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<long long> raw;
    raw.push_back(0);
    for(int i = 1; i < N; i++){
        if(S[i] != S[i - 1]) raw.push_back(i);
    }
    raw.push_back(N);
    long long siz = raw.size() - 1;
    long long ans = 0;
    for(int i = 0; i < raw.size(); i++){
        if(S[raw[i]] == '0') ans = max(ans, raw[min(i + 2 * K, siz)] - raw[i]);
        else ans = max(ans, raw[min(i + 2 * K + 1, siz)] - raw[i]);
    }
    cout << ans << endl;
}