#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>


using namespace std;

int main() {
    long long int N, a, sum =0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a;
        while(a % 2 ==0){
            sum ++;
            a /= 2;
        }
    }

    cout << sum;

    return 0;

}

