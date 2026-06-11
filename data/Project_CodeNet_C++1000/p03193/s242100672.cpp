#include <bits/stdc++.h>
using namespace std;
 
int main(){
    long long N, H, W;
    cin >> N >> H >> W;

    long long cnt = 0;

    for (int i = 0; i < N; i++){
        long long A, B;
        cin >> A >> B;

        if (A >= H && B >= W){
            cnt++;
        }
    }

    cout << cnt << endl;
}