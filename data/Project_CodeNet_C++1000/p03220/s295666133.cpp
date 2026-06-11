#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n, t, a;
    cin >> n;
    cin >> t >> a;
    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    t *= 1000;
    a *= 1000;

    int ans = 0;
    for(int i = 1; i < n; i++){
        if(abs(a-(t-h[i]*6)) < abs(a-(t-h[ans]*6))){
            ans = i;
        }
    }
    cout << ans+1 << endl;
    return 0;
}