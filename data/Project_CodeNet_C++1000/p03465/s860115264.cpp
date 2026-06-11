#include <numeric>
#include <iostream>
using namespace std;

class BSet {
    unsigned long long *data;
    int length, max_val;
public:
    BSet(int n) : max_val(n) {
        length = n / 64 + 1;
        data = new unsigned long long[length];
        fill(data, data+length, 0);
        data[0] = 1;
    }
    void add(int x) {
        int y = x / 64, z = x % 64;
        for (int i = length-y-1; i >= 0; i--) {
            const unsigned long long v = data[i],
                low = v << z, high = z ? v >> (64 - z) : 0;
            if (i + y + 1 < length) data[i+y+1] |= high;
            data[i+y] |= low;
        }
    }
    int get_max() {
        for (int r = max_val; r >= 0; r--)
            if (data[r / 64] & (1ULL << (r % 64))) return r;
        return 0;
    }
};

int main() {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    int sum = accumulate(a, a+n, 0);

    BSet s(sum/2);
    for (int x : a) s.add(x);
    cout << sum - s.get_max() << endl;
}
