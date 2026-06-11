#include <iostream>
#include <algorithm>
#include <cmath>

int main()
{
    using namespace std;
    
    int n, a[200000];
    long long int sadness = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] -= (i + 1);
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        sadness += abs(a[i] - a[n / 2]);
    }
    cout << sadness << endl;
    return 0;
}
