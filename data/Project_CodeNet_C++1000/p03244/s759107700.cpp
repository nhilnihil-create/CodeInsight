#include <iostream>
using namespace std;

int N;

int v1[100010] = {};
int v2[100010] = {};

int main() {
    cin >> N;
    for(int i = 0; i < N; ++i) {
        int v;
        cin >> v;
        if(i % 2 == 0) {
            v1[v]++;
        } else {
            v2[v]++;
        }
    }
    int f1 = -1, i1 = -1, n1 = -1;
    int f2 = -1, i2 = -1, n2 = -1;
    for(int i = 0; i < 100010; ++i) {
        if(f1 < v1[i]) {
            n1 = f1;
            f1 = v1[i];
            i1 = i;
        } else if(n1 < v1[i]) {
            n1 = v1[i];
        }

        if(f2 < v2[i]) {
            n2 = f2;
            f2 = v2[i];
            i2 = i;
        } else if(n2 < v2[i]) {
            n2 = v2[i];
        }
    } 
    if(i1 == i2) {
        cout << min((N - f1 - n2), (N - f2 - n1)) << endl;
    } else {
        cout << N - f1 - f2 << endl;
    }
}
