#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
using namespace std;
#define int long long
typedef vector<int> vi;

signed main(){
    int N, x;
    cin >> N >> x;
    vi a(N);
    rep(i, N) cin >> a[i];

    sort(a.begin(), a.end());
    
    int counter = 0;
    rep(i, N){
        x -= a[i];
        if(x < 0) break;
        counter++;
    }

    if(x > 0) counter--;

    cout << counter << endl;
    return 0;
}