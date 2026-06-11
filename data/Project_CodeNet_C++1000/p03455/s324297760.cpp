#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    int result = N * M % 2;

    cout << ((result != 0) ? "Odd" : "Even");
}