#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<char,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int a, b, k;
    cin >> a >> b >> k;

    rep(i, k){
        if(i % 2 == 0){
            if(a % 2 == 1){
                a--;
            }
                a /= 2;
                b += a;
        }else{
            if(b % 2 == 1){
                b--;
            }
                b /= 2;
                a += b;
        }
    }

    cout << a << " " << b << endl;


    return 0;
}