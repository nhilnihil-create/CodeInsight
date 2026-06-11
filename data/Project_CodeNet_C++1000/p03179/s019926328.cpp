#include <bits/stdc++.h>

#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    using namespace std;
    int n;
    cin >> n;
    string S;
    cin >> S;

    const ll mod = 1'000'000'007;

    vector<int> pre(n + 2, 0), suf(n + 2, 0), A(n + 2);
    auto make_pre_suf = [n, &pre, &suf, &A](){
        pre[0] = 0;
        for(int i = 1; i <= n; i++)
            pre[i] = (pre[i - 1] + A[i]) % mod;
        pre[n + 1] = 0;
        suf[n + 1] = 0;
        for(int i = n; i > 0; i--)
            suf[i] = (suf[i + 1] + A[i]) % mod;
        suf[0] = 0;
    };

    A[1] = 1;
    make_pre_suf();
    for(int i = 0; i < S.size(); i++) {
        for(int j = 1; j < i + 3; j++)
            if(S[i] == '<')
                A[j] = pre[j - 1];
            else
                A[j] = suf[j];
        make_pre_suf();
    }

    ll result = 0;
    for(int i = 1; i <= n; i++)
        result = (result + A[i]) % mod;

    cout << result << "\n";

    return 0;
}
