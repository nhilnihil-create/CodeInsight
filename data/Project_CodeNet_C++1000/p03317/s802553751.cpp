#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    cout << (n+k-3)/(k-1) << endl;
    return 0;
}