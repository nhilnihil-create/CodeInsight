#include <iostream>
#include <cmath>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int A,B,C;
    cin >> A >> B >> C;
    cout << ((A<C && C<B || C<A && B<C) ? "Yes" : "No") << endl;
}