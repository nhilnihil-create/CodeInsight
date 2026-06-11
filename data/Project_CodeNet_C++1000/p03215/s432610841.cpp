#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)




int main()
{

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif

    int n, k, l, counter;
    cin >> n >> k;
    ll s, ans, a[n], a_sum[n+1], m, p;
    vector<ll> number, new_number;
    s = 0;
    a_sum[0] = 0;
    rep(i, n){
        cin >> a[i];
        s += a[i];
        a_sum[i+1] = s;
    }
    rep(i, n)
        rep2(j, i, n){
            number.push_back(a_sum[j+1] - a_sum[i]);
        }
    l = 0;
    m = a_sum[n];

    while (m){
        l++;
        m /= 2;
    }

    ans = 0;
    rep(i, l){
        p = pow(2, l-i-1);
        counter = 0;
        for (auto x : number){
            if (x & p){
                counter++;
                new_number.push_back(x);
            }
        }
        if (counter >= k){
            ans += p;
            number = new_number;
        }
        new_number.clear();
    }
    cout << ans << endl;
    return 0;
}
