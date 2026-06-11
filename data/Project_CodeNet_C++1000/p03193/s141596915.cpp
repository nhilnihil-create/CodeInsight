#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, H, W;
    cin >> N;
    cin >> H;
    cin >> W;

    int cnt=0;

    for(int i=0; i<N; i++){
        int a, b;
        cin >> a;
        cin >> b;
        if(a>=H && b>=W) cnt++;
    }

    cout << cnt << endl;
}