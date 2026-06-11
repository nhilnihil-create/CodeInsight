#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, h, w;
    cin >> n >> h >> w;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] >= h && b[i] >= w) ans++;
    }
    cout << ans << endl;
    return 0;
}