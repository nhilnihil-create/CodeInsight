#include<bits/stdc++.h>

int main(){
    using namespace std;
    size_t N;
    cin >> N;
    vector<pair<pair<size_t, size_t>, pair<size_t, size_t>>> A(1 << N);
    size_t cnt{0};
    for(auto& i : A){
        cin >> i.first.first;
        i.first.second = ++cnt;
    }
    auto add = [](auto& a, auto b){
        if(a.first < b.first){
            swap(a.first, a.second);
            a.first = b.first;
        }else if(a.first != b.first && a.second < b.first) a.second = b.first;
        if(a.second < b.second)a.second = b.second;
    };
    for(size_t i = 0; i < N; ++i)for(size_t j = 0; j < 1UL << N; ++j)if(1 & (j >> i))add(A[j], A[j ^ (1 << i)]);
    vector<size_t> ans;
    transform(A.begin() + 1, A.end(), back_inserter(ans), [](auto a){return a.first.first + a.second.first;});
    partial_sum(ans.begin(), ans.end(), ans.begin(), [](auto a, auto b){return max(a, b);});
    for(const auto i : ans)cout << i << endl;
}