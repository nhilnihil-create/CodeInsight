#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,Y;
    cin >> N >> Y;
    int sum = 0;
    int a,b,c;
    a = b = c = -1;
    for (int i = 0; i <= N; i++){
        for (int j = 0; j <= N; j++){
            if ((0 <= (N - i - j)) && ((N - i - j) <= N)){
                sum = 10000 * i + 5000 * j + 1000 * (N - i - j);
                if (sum == Y){
                    a = i;
                    b = j;
                    c = N - i - j;
                }
            }
        }
    }
    cout << a << " " << b << " " << c << endl;
}