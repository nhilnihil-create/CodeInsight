#include<bits/stdc++.h>

int main(){
    using namespace std;
    unsigned long N;
    cin >> N;
    vector<unsigned long> ip(N);
    for(unsigned long i{0}, p; i < N; ++i){
        cin >> p;
        ip[--p] = i;
    }
    unsigned long ans{0}, prev{N}, tmp{0};
    for(const auto& i : ip){
        if(i < prev)tmp = 0;
        prev = i;
        ans = max(ans, ++tmp);
    }
    cout << N - ans << endl;
    return 0;
}