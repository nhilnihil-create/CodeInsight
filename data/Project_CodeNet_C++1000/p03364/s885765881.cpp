#include<bits/stdc++.h>
using namespace std;

int main(){
    size_t N;
    cin >> N;
    vector<vector<int>> v(N, vector<int>(N));
    for(auto& i : v){
        string s;
        cin >> s;
        transform(s.begin(), s.end(), i.begin(), [](auto i){return i - 97;});
    }
    size_t ans{0};
    for(size_t k = 0; k < N; ++k)ans += [&]{
        for(size_t j = 0; j < N; ++j)for(size_t i = 0; i < N; ++i)if(v[i][(j + k) % N] != v[j][(i + k) % N])return 0UL;
        return N;
    }();
    cout << ans << endl;
    return 0;
}