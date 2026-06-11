#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<long long> > vvll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define p_q priority_queue

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 2005
int n;
int a[MN];

bitset<MN*MN> ree;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int sm = 0;
    F0R(i, n){
        cin >> a[i];
        sm += a[i];
    }
    sort(a, a+n);
    ree[0] = 1;
    F0R(i, n){
        ree = ree | (ree << a[i]);
    }

    int mid = (sm+1)/2;
    while(!ree[mid]) mid++;
    cout << mid << "\n";

    return 0;
}
