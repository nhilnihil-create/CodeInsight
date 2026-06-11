#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(ll N, ll K)
{
    ll ans;     // Número de pares (a, b) com a % b in [0, K - 1]

    // Para b in [1, K] o resto sempre está no intervalo [0, K - 1],
    // para qualquer a in [1, N]
    ans = N*K;

//using ii = pair<int, int>;
//cout << "Total: " << N*N << " pares\n";
//set<ii> xs;

//for (int b = 1; b <= K; ++b)
 //   for (int a = 1; a <= N; ++a)
  //      if (a % b < K)
   //         xs.insert(ii(a, b));

//cout << "set size = " << xs.size() << '\n';
//cout << "New  total = " << N*N - xs.size() << '\n';

    // Para b in [K + 1, N]
    for (ll i = K + 1; i <= N; ++i)
    {
        // Cada múltiplo completo tem K números com resto entre 0 e K - 1
        auto q = N / i;
        ans += (K*q);

        // O resto tem K - 1 números, no máximo, com resto entre 1 e K - 1
        if (K)
        {
            auto r = N % i;
            ans += min(r, K - 1);
        }

//cout << q << " multiplos de " << i << ", resto = " << r << '\n';
//cout << "removendo " << K*q << " dos múltiplos, " << min(r, K - 1) << " do resto\n";
    }

    // A resposta é o complementar de todos os pares
    return N*N - ans;
}

int main()
{
    int N, K;
    cin >> N >> K;

    cout << solve(N, K) << '\n';

    return 0;
}
