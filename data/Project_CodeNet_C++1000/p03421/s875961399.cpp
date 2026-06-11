#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    int n, a, b;
    cin >> n >> a >> b;
    if(n + 1 < a + b){
        cout << -1 << endl;
        return 0;
    }
    if(b == 1){
        if(a != n){
            cout << -1 << endl;
            return 0;
        }
        for(int i = 1; i <= n; i++){
            cout << i << endl;
        }
        return 0;
    }
    vector<int> ans;
    for(int i = n - a + 1; i <= n; i++){
        ans.push_back(i);
    }
    b--;
    int now = n - a + 1;
    if(b > now){
        cout << -1 << endl;
        return 0;
    }
    while(true){
        a = min(a, now - 1);
        a = min(a, now - 1 - (b - 1));
        //cout << now << " " <<  a << endl;
        if(a == 0) break;
        if(b == 0){
            cout << -1 << endl;
            return 0;
        }
        b--;
        for(int i = now - a; i < now; i++){
            ans.push_back(i);
        }
        now = now - a;
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    for(int i = 1; i <= n - ans.size(); i++){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
