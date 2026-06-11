#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n, k, cnt=0;
    cin >> n >> k;
    vector<int>a(200001,0);
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        a[tmp]++;
    }
    sort(a.rbegin(), a.rend());
    int ans = 0;
    for(int i=0; i<k; i++){
        ans += a[i];
    }
    cout << n - ans << endl;
    return 0;
}