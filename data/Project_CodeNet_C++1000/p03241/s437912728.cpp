#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N, M; cin >> N >> M;
    int x = M/N;
    for (int i = x; i > 0; i--){
        if(M%i == 0){
            cout << i << endl;
            break;
        }
    }

    return 0;
}