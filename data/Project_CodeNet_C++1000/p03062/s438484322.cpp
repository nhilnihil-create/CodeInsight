#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;


int main() {
    int N;
    cin >> N;
    vector<int> A(N);

    int num_minus = 0;
    int64_t sum = 0;
    
    rep(i, N) { 
        cin >> A[i];
        if(A[i] < 0) {
            A[i] = A[i] * -1;
            num_minus++;
        }
        sum += A[i];
    }

    if(num_minus % 2 == 0) {
       cout << sum << endl; 
    } else {
        sort(A.begin(), A.end());
        cout << sum - A[0]*2 << endl;
    }


    return 0;
}

