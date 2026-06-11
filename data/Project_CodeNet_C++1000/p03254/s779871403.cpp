#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<iomanip>
#include<map>
#include<utility>
#include<string>
#include<unordered_map>
#include<queue>

template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } return false; }

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int gcd(int a, int b){return b ? gcd(b, a%b) : a;}

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(x < a[i]){
            cout << ans << endl;
            return 0;
        }
        x -= a[i];
        ans++;
    }
    if(x != 0) cout << ans-1 << endl;
    else cout << ans << endl;
    return 0;
}
