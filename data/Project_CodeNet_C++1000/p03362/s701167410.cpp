#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repr(i, a, b) for (int i=a; i<(b); ++i)
#define reprev(i, n) for (int i=n-1; i>=0; --i)
#define reprrev(i, a, b) for (int i=b-1; i>=(a); --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<int> Eratosthenes(const int N) {
    vector<bool> is_prime( N + 1 );
    for( int i = 0; i <= N; i++ ) {
        is_prime[ i ] = true;
    }
    vector<int> P;
    for( int i = 2; i <= N; i++ ) {
        if( is_prime[ i ] ) {
            for( int j = 2 * i; j <= N; j += i ) {
                is_prime[ j ] = false;
            }
            P.emplace_back( i );
        }
    }
    return P;
}

int main() {
    cout << fixed << setprecision(10);
    
    int N; cin >> N;

    vector<int> pr = Eratosthenes(2000);
    int num_prime = 0;
    int ni = 0;
    while (pr[ni] < 10) {
        ni += 1;
    }

    while (num_prime < N) {
        while (pr[ni] % 10 != 1) {
            ni += 1;
        }
        cout << pr[ni] << " ";
        ni += 1;
        num_prime += 1;
    }
    cout << endl;
    return 0;
}