#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
#include <array>
#include <cmath>
#include <set>
#include <numeric>

using namespace std;

template <typename T>
using TABLE = vector<vector<T>>;

long long PRIME = 1e9 + 7;
long long PRIME2 = 998244353;


int MAX_INDEX = 40;


int main(){
    long long N;
    cin >> N;

    if(N % 2 == 0){
        long long half = N / 2;
        long long M = N * half - N;

        cout << M << endl;

        for(int i = 1; i <= half; ++i){
            for(int j = i + 1; j <= N - i; ++j){
                cout << i << " " << j << endl;
                cout << N - i + 1 << " " << j << endl;
            }
        }
    }
    else{
        long long _N = N - 1;
        long long half = _N / 2;
        long long M = _N * half - _N + N - 1;

        cout << M << endl;

        for(int i = 1; i <= half; ++i){
            for(int j = i + 1; j <= _N - i; ++j){
                cout << i << " " << j << endl;
                cout << _N - i + 1 << " " << j << endl;
            }
        }

        for(int i = 1; i <= _N; ++i){
            cout << i << " " << N << endl;
        }
    }
}
