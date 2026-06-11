#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int ans = 1;
    long long int n, p;

    cin >> n >> p;

    if (n == 1)  {
        cout << p << endl;
        return 0;
    }

    long long int tmp;
    int cont;
    for (int i=2; i<=sqrt(p)+1; i++) {
        tmp = p;
        cont = 0;
        while (tmp%i == 0) {
            cont++;
            tmp = tmp/i;
        }
        if (cont >= n) ans = i;//i * (cont/n);
    }

    cout << ans << endl;

    return 0;
}