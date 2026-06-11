#include "bits/stdc++.h"
using namespace std;


#include "bits/stdc++.h"
using namespace std;
int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    int ichi;
    ichi = max({ a,b,c });
    int nokori = a + b + c - ichi;
    for (int i = 1; i <= k; i++) {
        ichi *= 2;
    }
    cout << nokori + ichi << endl;
}
