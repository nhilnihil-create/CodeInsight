#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<pair<int, int>> vpii;

#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(x) (x).begin(),(x).end()
#define INF 1000000000 //4*10^9
#define MOD 1000000007 //10^9+7

int main()
{
    int N;
    cin >> N;
  
    rep(i, 3500)rep(j, 3500) {
        ll h = i + 1;
        ll n = j + 1;
        if ((4 * h * n) > N * (h + n) && (N * h * n)%((4*h*n)-N*(h+n))==0){
            cout << h<<" " << n<< " "<< (N * h * n)/((4 * h * n) - N * (h + n)) << endl;
            return 0;
        }
    }
    
}