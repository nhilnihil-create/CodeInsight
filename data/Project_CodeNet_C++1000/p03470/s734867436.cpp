#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int d[110];
    int N;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> d[i];
    }
    sort(d, d+N);
    reverse(d, d+N);

    int count = 0;
    for(int i = 0; i < N; i++) {
        if(d[i] != d[i+1]) {
            count++;
        }
    }
    cout << count << endl;
}