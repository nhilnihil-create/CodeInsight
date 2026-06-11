#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int d[n];
    for (int i = 0; i < n; i++) cin >> d[i];

    int cnt = 1;
    
    for (int i = 0; i < n; i++) {
        bool cnt_fl = false;
        for (int j = i + 1; j < n; j++){
            cnt_fl = true;
            if (d[i] == d[j]) {
                cnt_fl = false;
                break;
            }
        }
        if (cnt_fl == true) cnt++;
    }

    cout << cnt << endl;
}