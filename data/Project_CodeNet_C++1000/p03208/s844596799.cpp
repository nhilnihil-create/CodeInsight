#include<bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;

int main()
{
    long k,n;
    cin >> n >> k;
    vec<long> h(n);
    for (auto &&e : h)
    {
        cin >> e;
    }
    sort(h.begin(),h.end());
    long ans = 1000000007;
    for (long i = 0; i+k-1 < n; i++)
    {
        ans = min(h.at(i+k-1) - h.at(i),ans);
    }
    cout << ans << endl;
}