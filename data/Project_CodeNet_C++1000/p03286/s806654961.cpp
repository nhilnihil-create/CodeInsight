#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ll n;   cin >> n;
    vector<int> s;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    int k = 0, tmp = 1;  
    while (n != 0) {
        if (n % 2)
            s.push_back(1);
        else 
            s.push_back(0);

        n -= s[k++];
        n /= -2;
    }
    for (int i = s.size()-1; i >= 0; i--)
        cout << s[i];
    cout << endl;
    return 0;
}