#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;


int main() {
    int a, b;
    cin >> a >> b;
    if (a + b == 15){
        cout << "+" << endl;
    }
    else if(a * b == 15){
        cout << "*" << endl;
    }
    else {
        cout << "x" << endl;
    }
}
