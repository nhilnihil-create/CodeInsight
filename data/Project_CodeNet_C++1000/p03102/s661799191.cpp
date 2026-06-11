#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int cnt[100005];
int main() {
    int n , m , c , t , count = 0;
    cin >> n >> m >> c;
    vector <int>  B(m);
    rep(i , m){
        cin >> B[i];
    }
    rep(i , n){
        int s = 0;
        rep(j , m){
            cin >> t;
            s += t * B[j];
        }
        if(s + c > 0){
        	count++;
        }
    }
    cout << count << endl;
}