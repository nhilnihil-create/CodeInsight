#include <bits/stdc++.h>

using namespace std;

int N;
string s;
map < string, map < string, int > > mp;

int main(){
    cin >> N >> s;
    reverse(s.begin() + N, s.begin() + 2 * N);
    for(int i = 0; i < (1 << N); ++i){
        string A, B;
        for(int j = 0; j < N; ++j){
            if(i & (1 << j)){
                A += s[j];
            }
            else{
                B += s[j];
            }
        }
        ++mp[A][B];
    }
    long long ans = 0;
    for(int i = 0; i < (1 << N); ++i){
        string A, B;
        for(int j = N; j < 2 * N; ++j){
            if(i & (1 << (j - N))){
                A += s[j];
            }
            else{
                B += s[j];
            }
        }
        ans += mp[A][B];
    }
    printf("%lld\n", ans);
    return 0;
}
