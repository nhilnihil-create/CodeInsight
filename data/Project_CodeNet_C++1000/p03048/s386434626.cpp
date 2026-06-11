#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PLL> VP;
#define rep(i,n) for (ll i=0; i<(ll)(n); i++)
#define repd(i,n) for (ll i=n-1; i>=0; i--)
#define rept(i,m,n) for(ll i=m; i<n; i++)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define PF push_front
#define PB push_back
#define SORT(V) sort((V).begin(), (V).end())
#define RVERSE(V) reverse((V).begin(), (V).end())
#define paired make_pair
#define PRINT(V) for(auto v : (V)) cout << v << " "

int main()
{
    int R,G,B,N;
    cin >> R >> G >> B >> N;
    ll count=0;
    int mina=R;
    mina=min(mina,G);
    mina=min(mina,B);
    for(int i=0; i<=N/mina; i++){
        for(int j=0; j<=N/mina; j++){
            if((N-(i*R)-(j*G))%B==0 && (N-(i*R)-(j*G))>=0){
                count++;
            }
        }
    }
    cout << count << endl;
}