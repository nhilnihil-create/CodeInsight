#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> data(1 << n);
    for(int i = 0; i < (1 << n); ++i)
        cin >> data[i];

    ll f, s, best = 0;
    for(int msk = 1; msk < (1 << n); ++msk){
        f = 0, s = -1;
        for(int sub = msk; sub > 0; sub = msk & (sub - 1)){
            if(data[sub] > data[f]){
                s = f;
                f = sub;
                continue;
            }
            if(s == -1 || (sub != f && data[sub] > data[s]))
                s = sub;
        }
        best = max(best, data[f] + data[s]);
        cout << best << "\n";
    }

    return 0;
}//RUL0