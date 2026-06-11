#include<bits/stdc++.h>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


using namespace std;


bool is_prime[ 5555551 ];
vector<int> P;
void Eratosthenes( const int N )
{
    for( int i = 0; i <= N; i++ )
    {
        is_prime[ i ] = true;//初期化
    }
    for( int i = 2; i <= N; i++ )
    {
        if( is_prime[ i ] )
        {
            for( int j = 2 * i; j <= N; j += i )
            {
                is_prime[ j ] = false;
            }
            P.emplace_back( i );
        }
    }
    is_prime[1] = false;
}

int main() {
    int N;
    cin >> N;
    Eratosthenes(555550);
    int ans[N];
    int ind = 0;
    rep(i, 555551) {
        if (is_prime[i] && i % 5 == 1) {
            ans[ind] = i;
            ind++;
        }
        if (ind == N) {
            break;
        }
    }

    rep(i, N) {
        cout << ans[i] << " ";
    }
    cout << endl << endl;
}