#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N;
    cin >> N;
    for (int h = 1; h <= 3500; h++){
        for (int w = 1; w <= 3500; w++){
            long long x = N * h * w;
            long long y = 4 * h * w - N * w - N * h;
            if (y <= 0) continue;
            if (x % y == 0){
                cout << h << " " << x / y << " " << w << endl;
                return 0;
            }
        }
    }
}