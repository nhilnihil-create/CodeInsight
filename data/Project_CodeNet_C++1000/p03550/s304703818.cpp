#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int N, Z, W;
    cin >> N >> Z >> W;
    vector<int> a(N);
    for(int i=0; i<N; i++) {
        cin >> a[i];
    }
    int X, Y;
    if(N == 1) {
        cout << abs(a[0] - W) << endl;
    } else {
        if(abs(a[N-1]-W) >= abs(a[N-2]-a[N-1])) {
            cout << abs(a[N-1]-W) << endl;
        } else {
            cout << abs(a[N-2]-a[N-1]) << endl;
        }
    }
    return 0;
}
