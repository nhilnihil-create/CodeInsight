#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, d, x;
    cin >> n;
    cin >> d >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int eatnum = 0;
    for(int i = 0; i < n; i++){
        eatnum += (d-1)/a[i] + 1;
    }

    cout << eatnum+x << endl;
    return 0;
}