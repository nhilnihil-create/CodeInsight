#include<bits/stdc++.h>

int main(){
    using namespace std;

    unsigned long N, H;
    cin >> N >> H;

    vector<unsigned long> B(N);
    unsigned long A{0};
    for(auto&& i : B){
        unsigned long a;
        cin >> a >> i;
        A = max(a, A);
    }
    auto it = partition(begin(B), end(B), [&A](const auto& i){return i > A;});
    const auto& sum = accumulate(begin(B), it, 0UL);
    if(sum < H)cout << it - begin(B) + (H - sum + A - 1) / A << endl;
    else{
        sort(begin(B), it, greater<>());
        partial_sum(begin(B), it, begin(B));
        cout << lower_bound(begin(B), it, H) - begin(B) + 1 << endl;
    }
    return 0;
}