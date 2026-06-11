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
    ll K, A, B;
    cin >> K >> A >> B;
    ll m=1;
    ll count=0;
    while(count!=K){
        if(m<A){
            m++;
            count++;
            continue;
        }
        if(count==K-1){
            m++;
            count++;
            continue;
            
        }
        if((m+2-m)<-A+B){
            m=m-A+B;
            count+=2;
            continue;
        }
        else{
            m++;
            count++;
        }
    }
    cout << m << endl;
}