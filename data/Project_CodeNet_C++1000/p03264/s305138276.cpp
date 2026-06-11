#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
using namespace std;

int main(void) {
    int N; cin >> N;
    int odd,even;
    even = N / 2;
    odd = N / 2;
    if (N % 2 == 1) odd++;
    cout << even * odd << endl;
}