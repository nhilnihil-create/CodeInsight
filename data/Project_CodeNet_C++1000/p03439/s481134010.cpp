//解説AC
//vacantをはかせてreturnする

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;


int main(){
    int n;
    cin >> n;

    int left = 0;
    //fflush
    cout << left << endl;
    string s;
    cin >> s;
    if (s == "Vacant") return 0;

    int right = n;

    while(right - left > 1){
        int mid = (right + left) / 2;
        cout << mid << endl;
        string t;
        cin >> t;
        if (t == "Vacant") return 0;
        else{
            if (((mid - left)%2 == 1 && s != t) || ((mid - left)%2 == 0 && s == t)){
                left = mid;
                s = t;
            }
            else right = mid;
        }
    }

    return 0;
}
