#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int n, K;
    cin >> n >> K;
    vector<int> A(n);
    rep(i, n) cin >> A[i];

    unordered_map<int, int> C;
    rep(i, n) C[A[i]] = 0;
    rep(i, n) C[A[i]]++;

    vector<int> cv;
    for (auto kv: C) {
        cv.push_back(kv.second);
    }

    sort(all(cv));

    if (cv.size() <= K) {
        put(0);
        return 0;
    }

    int sum = 0;
    rep(i, cv.size() - K) {
        sum += cv[i];
    }
    
    put(sum);

    return 0;
}