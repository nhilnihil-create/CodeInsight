#include <bits/stdc++.h>
using namespace std;

int A, B, C, X;
int sum, ans;

int main(){

    cin >> A >> B >> C >> X;
    sum = 0;
    ans = 0;

    for (int i=0; i<A+1; i++){
        for (int j=0; j<B+1; j++){
            for (int k=0; k<C+1; k++){
                sum = i*500 + j*100 + k*50;
                if (sum == X) ans++;
                sum = 0;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
