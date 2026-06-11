#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;


int main() {
    int N, ans = 0;
    cin >> N;
    for (int i = 0; i < 4; i++){
        if (N % 10 == 2){
            ans++;
        }
        N /= 10;
    }
    cout << ans << endl;
}

