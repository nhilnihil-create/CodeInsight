#include <iostream>
#include <cmath>
using namespace std;

int cnt_digits(long long N) {
    int digits = 0;

    while(N > 0) {
        N /= 10;
        digits++;
    }
    return digits;
}

int main() {
    int N;
    cin >> N;
    int x[N], y[N], h[N];
    for(int i = 0; i < N; i++) {
        cin >> x[i] >> y[i] >> h[i];
    }
    int MAX = 100;
    for(int posY = 0; posY <= MAX; posY++) {
        for(int posX = 0; posX <= MAX; posX++) {
            int needH = -1;

            for(int i = 0; i < N; i++) {
                if(h[i] > 0) {
                    int tmp = h[i] + abs(posY - y[i]) + abs(posX - x[i]);
                    if(needH == -1) {
                        needH = tmp;
                    } else {
                        if(needH != tmp) {
                            needH = -2;
                            break;
                        }
                    }
                }
            }
            if(needH == -2) continue;

            for(int i = 0; i < N; i++) {
                if(h[i] == 0) {
                    int dist = abs(posY - y[i]) + abs(posX - x[i]);
                    if(needH > dist) {
                        needH = -2;
                        break;
                    }
                }
            }
            if(needH == -2) continue;
            cout << posX << " " << posY << " " << needH << endl;
        }
    }
}