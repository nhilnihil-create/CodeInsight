#include<bits/stdc++.h>
using namespace std;

int main(){
    constexpr size_t maxNA = 4000000;
    size_t N;
    cin >> N;
    size_t S{0};
    bitset<maxNA> hoge;
    hoge[0] = 1;
    for(size_t i = 0, A; i < N; ++i, S += A, hoge |= hoge << A)cin >> A;
    for(size_t k = (S + 1) / 2; k <= S; ++k)if(hoge[k]){
        cout << k << endl;
        return 0;
    }
}