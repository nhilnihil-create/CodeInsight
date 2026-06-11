#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int n;
    cin >> n;
    int d, x;
    cin >> d >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        x++;
        int t = 1;
        while(t*a[i]+1 <= d){
            x++;
            t++;
        }
    }
    cout << x << endl;
    return 0;
}