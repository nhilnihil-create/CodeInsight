#include <iostream>
#include <queue>
#include <map>
#include <deque>
#include <algorithm>
#include <set>
#include <string>
#include <math.h>
#include <stdio.h>
#include <iomanip>
#include <cstring>
#include <climits>
#include <iostream>


#define ll long long
#define p 1000000007
#define INF LONG_LONG_MAX
using namespace std;

std::map<ll,ll>::iterator lessthan(map<ll,ll> &mp, ll k){

    std::map<ll,ll>::iterator it = mp.lower_bound(k);
    if(it != mp.begin()) {
        return --it;
    }
    return mp.end();
}
ll factorial(ll n)
{
    if (n == 1 || n == 0)
        return 1;
    return  n * factorial(n - 1);
}


//matrix exp

struct Matrix
{
    vector< vector<ll> > mat; // the contents of matrix as a 2D-vector
    int n_rows, n_cols; // number of rows and columns

    Matrix(vector< vector<ll> > values): mat(values), n_rows(values.size()),
        n_cols(values[0].size()) {}

    static Matrix identity_matrix(int n)
    {
        // Return I_n - the identity matrix of size n.
        // This function is static, because it creates a new Matrix instance
        vector< vector<ll> > values(n, vector<ll>(n, 0));
        for(int i = 0; i < n; i++)
            values[i][i] = 1;
        return values;
    }

    Matrix operator*(const Matrix &other) const
    {
        int n = n_rows, m = other.n_cols;
        vector< vector<ll> > result(n_rows, vector<ll>(m, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < n_cols; k++) {
                    result[i][j] = (result[i][j] + mat[i][k] * 1ll * other.mat[k][j]) % p;
                }
            }
        // Multiply matrices as usual, then return the result as the new Matrix
        return Matrix(result);
    }

    inline bool is_square() const
    {
        return n_rows == n_cols;
    }
};

Matrix fast_exponentiation(Matrix m, ll power)
{
    Matrix result = Matrix::identity_matrix(m.n_rows);

    while(power) {
        if(power & 1)
            result = result * m;
        m = m * m;
        power >>= 1;
    }

    return result;
}
 vector<ll> dp;
 vector<ll> dpG;

 void help(ll mask, int ind, ll combined, int n)
 {
     if (ind >= n)
        dpG[mask | combined] = max(dpG[mask | combined], dpG[mask] + dp[combined]);

     else{
        help(mask, ind + 1, combined, n);
        if (!((1 << ind) & mask))
            help(mask, ind + 1, combined | (1 << ind), n);
     }
 }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll arr[n][n];
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n;j++)
        {
            cin >> arr[i][j];
        }
    }
    dp.resize(1 << n, (- 1 * (INF -  1)));
    dp[0] = 0;
    for (ll mask = 0; mask < (1 << n); mask++)
    {
        for (ll i = 0; i < n; i++)
        {
            ll ans = 0;
            if (!(mask & (1 << i)))
            {
                for (ll j = 0; j < n; j++)
                {
                    if ((1 << j) & mask)
                       ans += arr[i][j];
                }
                dp[mask | (1 << i)] = ans + dp[mask];
            }
        }
    }
    dpG.resize(1 << n, (-1 * (INF - 1)));
    dpG[0] = 0;
    for (ll mask = 0; mask < (1 << n); mask++)
    {
        help(mask, 0,0,n);
    }
    /*for (ll mask = 0; mask < (1 << n); mask++)
    {
        cout << mask << ' ' << dp[mask] << ' ';
        cout << mask << ' ' << dpG[mask];
        cout << '\n';
    }*/
    cout << dpG[(1 << n) - 1];
    /*std::cout<<std::fixed;
    std::cout<<std::setprecision(10)<<ans;*/
             //   dp[i][i + 1 + j] = min(dp[i][i + j] + (pre[i + j + 2] - pre[i]),dp[i + 1][i + 1 + j] + (pre[i + j + 2] - pre[i]));

    return 0;
}
