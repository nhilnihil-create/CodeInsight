#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N;
    int T, A;
    cin >> N >> T >> A;

    int h[N];
    for(int i = 0; i < N; i++){
        cin >> h[i];
    }

    float min = 114514;
    int ans = 1;
    for(int i = 0; i < N; i++){
        float sa = A - T + 0.006*h[i];
        if(sa < 0) sa = 0-sa;
        if(min > sa) {
            min = sa;
            ans = i+1;
        }
    }

    cout << ans << endl;
}