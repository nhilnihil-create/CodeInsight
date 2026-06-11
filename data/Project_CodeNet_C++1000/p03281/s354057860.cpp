#include <iostream>
#include <set>

using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    int ans = 0;
    for(int i = 1; i <= N; i += 2) {
        int count = 0;
        for(int j = 1; j <= i; j++) {
            if(i % j == 0) {
                count++;
            }
        }
        if(count == 8) ans++;
    }
    cout << ans << endl;
    return 0;
}