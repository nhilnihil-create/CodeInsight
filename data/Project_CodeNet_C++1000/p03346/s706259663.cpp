#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

int main() {
    int N;
    cin >> N;
    int P[N];
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    int a[N];
    for (int i = 0; i < N; i++) {
        a[P[i] - 1] = i;
    }
    int big = 1;
    int now = 1;
    for (int i = 0; i < N - 1; i++) {

        if (a[i] < a[i + 1]) {
            now++;
        } else {

           now=1;
        }
        big=max(big,now);
    }
    cout << N-big << endl;
    /*for(int i=0;i<N;i++){
        cout<<a[i]<<endl;
    }*/

}











