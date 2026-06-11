#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

const int lim = 1000000007;

int main(){
    int N, Y;
    cin >> N >> Y;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            if(i + j > N) break;
            int k = N - (i + j);
            if(i * 10000 + j * 5000 + k * 1000 == Y){
                cout << i << " " << j << " " << k << endl;
                return 0;
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
    return 0;
}