#include <iostream>
#include <vector>
#include <map>
using namespace std;

void dec(map<long long, long long> &ma, long long a) {
    ma[a]--;
    if (ma[a] == 0) {
        ma.erase(a);
    }
}

int main() {
    int N; cin >> N;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    map<long long, long long> ma;
    for (int i = 0; i < N; ++i) ma[-a[i]]++;

    long long res = 0;
    for (int i = 0; i < N && !ma.empty(); ++i) {
        long long val = -ma.begin()->first;
            
        dec(ma, -val);
        long long po = 1;
        while (po <= val) po *= 2;
        long long rem = po - val;
        if (ma.count(-rem)) {
            ++res;
            dec(ma, -rem);
        }
    }
    cout << res << endl;
}