#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) (v).begin(),(v).end()
#define out(a) cout << (a) << endl
using namespace std;
using ll = long long;
int main(){
    int n, m, X, Y;
    int ans=1000;
    cin >> n >> m >> X >> Y;
    vector<int> x(n);
    vector<int> y(m);
    rep(i, n) cin >> x[i];
    rep(i, m) cin >> y[i];
    
    int maxx = *max_element(all(x));
    int miny = *min_element(all(y));

    int start = max(maxx, X);
    int end = min(miny, Y);

    for(int i=start; i<=end; i++){
        if(X < i && i < Y && maxx < i && i <= miny){
            ans = i;
        }
    }

    if(ans == 1000) out("War");
    else out("No War");
    
}