#include <iostream>
#include <string>
#include <cmath>
using namespace std;
 
int main(void) {
    string s;
    int n, k;
    cin >> n >> k >> s;
    s[k - 1] = s[k - 1] + 32;
    cout << s << endl;
    return 0;
}
