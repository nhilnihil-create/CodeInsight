#include <bits/stdc++.h>
using namespace std;

int nth_bit(int64_t num, int n){
    return (num >> n) & 1;
}

int main(){
    int N;
    string S;
    cin >> N >> S;

    map<string, int64_t> mp1, mp2;
    for(int b=0; b<(1<<N); b++){
        string s;
        for(int k=0; k<2; k++){
            for(int i=0; i<N; i++) if(nth_bit(b, i) == k) s.push_back(S[i]);
            s.push_back('!');
        }
        mp1[s]++;
    }
    for(int b=0; b<(1<<N); b++){
        string s;
        for(int k=0; k<2; k++){
            for(int i=0; i<N; i++) if(nth_bit(b, i) == k) s.push_back(S[2*N-1-i]);
            s.push_back('!');
        }
        mp2[s]++;
    }
    int64_t ans = 0;
    for(auto& p : mp1){
        string s = p.first;
        int64_t v = p.second;
        if(mp2.count(s)) ans += v * mp2[s];
    }
    cout << ans << endl;
}