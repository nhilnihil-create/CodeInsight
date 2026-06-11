#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int A, B, C, X;
    cin >> A >> B >> C >> X;
    int temp = 0;
    int ans = 0;
    for (int i = 0; i <= A; i++){
        for(int j = 0; j <= B; j++){
            for (int p = 0; p <= C; p++){
                temp = 500 * i + 100 * j + 50 * p;
                if(temp == X){
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}