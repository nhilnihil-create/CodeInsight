#include <bits/stdc++.h>
using namespace std;
int main(){
    long long N, answer = 1;
    string S;
    cin >> N >> S;
    unordered_map<char,long long> mp;
    for (int i = 0; i < N; i++) {
        mp[S.at(i)]++;
    }
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        answer *= itr->second + 1;
        answer %= 1000000007;
    }
    answer += 1000000006;
    answer %= 1000000007; 
    cout << answer << endl;
}