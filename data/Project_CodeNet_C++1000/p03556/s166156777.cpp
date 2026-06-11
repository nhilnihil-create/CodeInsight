#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int main() {
    int N;
    cin >> N;
    int ans = 0;
    for(int i = 1; i <= 31622; i++){
        if(i * i <= N){
            ans = i;
        }
    }
    cout << ans * ans << endl;
}