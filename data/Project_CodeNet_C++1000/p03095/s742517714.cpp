#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define ALL(A) A.begin(),A.end()

const ll P = 1e9+7;

int main()
{
    ll N;
    cin >> N;

    string S;
    cin >> S;

    map<char,int> Alpha;
    for(int i=0;i<N;i++)
    {
        Alpha[S[i]]++;
    }

    ll ans = 1;

    for(auto x : Alpha)
    {
        ans *= (x.second+1);
        ans %= P;
    }

    cout << ans-1 << endl;

    return 0;
}