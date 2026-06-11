#include<bits/stdc++.h>
using namespace std;
const int limit = 200050;

int main(){
    int n;
    cin >> n;

    int a[limit];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] = a[i] - i - 1;
    }

    sort(a, a + n);

    int b = (n % 2 == 0) ? a[n / 2 - 1] : a[(n + 1) / 2 - 1];

    long long f = 0;
    for(int i = 0; i < n; i++) f += abs(a[i] - b);

    cout << f << endl;

    return 0;
}
