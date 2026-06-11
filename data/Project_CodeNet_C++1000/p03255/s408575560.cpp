#include <bits/stdc++.h>

int main(){
    using namespace std;

    unsigned long N, X;
    cin >> N >> X;

    vector<long> x(N);
    for(auto& i : x)cin >> i;
    reverse(x.begin(), x.end());
    partial_sum(x.begin(), x.end(), x.begin());

    unsigned long ans(numeric_limits<long>::max());
    for(unsigned long i = 1; i <= N; ++i)
        [&]{
            unsigned long na((N + i) * X + 5 * x[N - 1]);
            for(unsigned long j = 2 * i - 1; j < N; j += i)
                if(ans < (na += 2 * (x[N - 1] - x[j])))return;
            if(na < ans)ans = na;
        }();
    cout << ans << endl;
}