#include <bits/stdc++.h>
using namespace std;

int main() {
    int A,B,K,ans=101,i=0;
    cin >> A >> B >> K;
    while (i<K) {
        ans--;
        if (A%ans==0 && B%ans==0) {
            i++;
        }
    }
    cout << ans << endl;
}