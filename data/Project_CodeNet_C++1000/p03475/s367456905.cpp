#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> c(n+10, 0), s(n+10, 0), f(n+10, 0);
    for(int i = 1; i < n; i++) cin >> c[i] >> s[i] >> f[i];

    for(int i = 1; i <= n; i++){
        int ans = 0;
        for(int j = i; j < n; j++){
            if(ans < s[j]){
                ans = s[j];
            }else if(ans % f[j] != 0){
                ans = f[j] * (ans/f[j] + 1);
            }
            ans += c[j];
        }
        cout << ans << endl;
    }
    return 0;
}