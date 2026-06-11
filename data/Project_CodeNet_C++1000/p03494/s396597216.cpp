#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, A, count, ans=1000000;
    cin >> N;
    for (int i = 0; i < N; i++) {
        count = 0;
        cin >> A;
        for(int j = 0;; j++) {
            if(A % 2 == 0) {
                A /= 2;
                count++;
            }
            else break;
        }
        if(ans > count) ans = count;
    }
    cout << ans << endl;
}