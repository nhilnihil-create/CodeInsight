#include <iostream>
#include <cstdlib>
#include <vector>
 
using namespace std;
// https://qiita.com/Clpsplug/items/81fe12400d4093a8fb5a
 
int main() {
    int A, B, K;
    cin >> A >> B >> K;
    int N;
    if (A > B) {
        N = B;
    } else {
        N = A;
    }

    vector<int> v;

    for (int i=1; i<N+1; i++) {
        if (A%i == 0 && B%i == 0) {
            v.push_back(i);
        }
    }

    cout << v[v.size()-K
    ] << endl;
}