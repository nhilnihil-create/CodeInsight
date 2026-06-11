#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

vector<int> v;

int f[3][3];
int main(){
    int n, m, x;
    cin >> n >> m;
    int minn = 10e6+100;
    for(int i=0; i<n; ++i){
        cin >> x;
        m-=x;
        minn = min (minn, x);
    }
    int ans = n;
    ans += m/minn;
    cout << ans << endl;

    return 0;
}