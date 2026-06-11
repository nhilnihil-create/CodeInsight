#include <bits/stdc++.h>
using namespace std;

int keta(long long N) {
    int res = 0;
    while(N>0) N /= 10, ++res;
    return res;
}

long long Res(int c, int keta) {
    long long res = c;
    --keta;
    while(keta-->0) {
        res *= 10LL;
        res += 9LL;
    }
    return res;
}

int Left_keta(long long N) {
    while(N >= 10) N /= 10;
    return int(N);
}

int keta_sum(long long N) {
    int res = 0;
    while(N>0) res += N%10, N /= 10;
    return res;
}

int main() {
    long long N;
    cin >> N;
    int C = Left_keta(N), Keta = keta(N);
    long long res1 = Res(C,Keta), res2 = Res(C-1,Keta);
    if(res1 <= N) {
        cout << C + 9*(Keta-1) << endl;
    } else {
        cout << C-1 + 9*(Keta-1) << endl;
    }
    return 0;
}