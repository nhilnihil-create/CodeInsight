#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;

    cout << (1900*M+100*(N-M)) * pow(2, M) << endl;
}
