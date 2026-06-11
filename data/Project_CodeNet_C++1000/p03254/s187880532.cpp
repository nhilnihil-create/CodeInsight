#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, x;
    cin >> N >> x;

    int a[10000];
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    sort(a, a+N);
    int count = 0;

    for(int i = 0; i < N; i++) {
        if(x > 0) {
            x -= a[i];
            count++;
        }      
    }
    
    if(x == 0) {
        cout << count << endl;
    } else {
        cout << count - 1 << endl;
    }
    
}