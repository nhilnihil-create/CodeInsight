#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

vector<int> V(101);

int main() {
    int N; cin >> N;
    for (int i = 2; i <= N; i++){
        int n = i;
        for (int j = 2; j <= N; j++){
            while(n % j == 0){
                V[j]++;
                n /= j;
                if(n == 1)break;  
            }
        }
    }
    int c2 = 0;
    int c4 = 0;
    int c14 = 0;
    int c24 = 0;
    int c74 = 0;

    for (int i = 2; i <= N; i++){
        if(V[i] >= 2)c2++;
        if(V[i] >= 4)c4++;
        if(V[i] >= 14)c14++;
        if(V[i] >= 24)c24++;
        if(V[i] >= 74)c74++;
    }

    int ans = c74 + (c24 * (c2-1)) + (c14 * (c4-1)) + ((c4 * (c4-1) / 2) * (c2 -2));
    cout << ans << endl;


    return 0;
}