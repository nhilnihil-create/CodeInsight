#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) ((int)(x).size())
using namespace std;

vector<int> Eratos(int MAX) {
    vector<int> is_prime(MAX+1,1);
    is_prime[0] = 0; is_prime[1] = 0;
    for(int i = 2; i < MAX+1; ++i) {
        if(!is_prime[i]) continue;
        for(int j = i*2; j < MAX+1; j += i) is_prime[j] = 0;
    }
    return is_prime;
}

int main()
{
    int n;
    cin >> n;

    vector<int> is_prime = Eratos(60000);
    vector<int> res;
    for(int i = 0; i <= 55555; i++) {
        if(sz(res) == n) break;
        if(is_prime[i] && i % 5 == 1) {
            res.push_back(i);
        }
    }

    rep(i,sz(res)) cout << res[i] << (i==n-1?"\n":" ");
    return 0;
}