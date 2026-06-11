#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define repd(i,a,b) for (int i=(a);i<(b);++i)
#define rep(i,n) repd(i,0,n)
#define reprd(i,a,b) for (int i=(a);i>=(b);--i)
#define repr(i,n) reprd(i,n,0)
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

using namespace std;

const ll BIG = 1000000007LL;

int inputValue(){
    int a;
    cin >> a;
    return a;
};

template<typename T>
void inputArray(T* p, int a){
    rep(i, a){
        cin >> p[i];
    }
};

template<typename T>
void inputVector(vector<T> * p, int a){
    rep(i, a){
        T input;
        cin >> input;
        p -> push_back(input);
    }
}

template <typename T>
void output(T a, int precision = 0) {
    if(precision > 0){
        cout << setprecision(precision)  << a << "\n";
    }
    else{
        cout << a << "\n";
    }
}

const int Max = 110;
int X, Y;

ll solve(int x, int y) {
    if (x % y == 0) return -1;
    return x;
}

int main(int argc, const char * argv[]) {
    cin >> X >> Y;

    output(solve(X, Y));

    return 0;
}