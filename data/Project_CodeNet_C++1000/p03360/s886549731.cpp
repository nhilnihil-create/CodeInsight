#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> a(3);
    for(int i = 0; i < 3; i++){
        cin >> a[i];
    }
    int k;
    cin >> k;
    sort(a.begin(), a.end());
    for(int i = 0; i < k; i++){
        a[2] *= 2;
    }
    cout << a[0] + a[1] + a[2] << endl;
    return 0;
}