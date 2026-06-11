#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int sum = 0;
    bitset<4000001> bs(1);
    
    for(int i=0; i<N; ++i) {
        int a;
        cin >> a;
        sum += a;
        bs |= (bs << a);
    }

    for(int j=(sum + 1) / 2; j <= 4000000; ++j) {
        if(bs[j]) {
            cout << j << endl;
            return 0;
        }
    }
}