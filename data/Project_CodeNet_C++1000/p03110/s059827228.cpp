#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N;
    double sum = 0;
    double base;
    string kind;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> base >> kind;
        if(kind == "JPY") {
            sum += base;
        } else {
            sum += (base * 380000);
        }
    }

    cout << sum << endl;
    return 0;
}
