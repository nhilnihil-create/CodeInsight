#include <bits/stdc++.h>
 
typedef long long ll;
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
#define rep(i, n) for (int i = 0; i < (n); ++i)
const double PI=3.14159265358979323846;

using namespace std;

int main() {

    int a, b;
    
    cin >> a >> b;

    string ans = "Odd";
    if (a*b % 2 == 0) ans = "Even";

    cout << ans << endl;
}