#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a[3];
string str;
int main(void){
    // Your code here!
    cin >> str;
    for (ll i = 0; i < str.length(); i++) {
        a[str[i] - 'a']++;
    }
    sort(a, a + 3);
    if (a[2] - a[0] <= 1) cout << "YES" << endl;
    else cout << "NO" << endl;
}
