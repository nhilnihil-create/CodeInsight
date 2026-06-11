#include <iostream>
#include <bitset>

using namespace std;

const int MAX = 2e3+10;
int N;
bitset<MAX*MAX> bs;

int main() {
    bs = 1;
    cin >> N;
    int s = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        bs |= (bs<<a);
        s += a;
    }
    
    for (int i = (s+1)/2; i <= s; i++) {
        if (bs[i]) {
            cout << i << endl;
            return 0;
        }
    }
}