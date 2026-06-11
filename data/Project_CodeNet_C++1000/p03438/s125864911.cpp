#include<bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main(void){

    int n, a[10005], b[10005];
    cin >> n;

    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];

    ll x = 0, y = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] > b[i]){
            x += a[i] - b[i];
        }else{
            y += (b[i] - a[i]) / 2;
        }
    }

    if(x <= y){
        cout << "Yes" << "\n";
    }else{
        cout << "No" << "\n";
    }

    return 0;
}
