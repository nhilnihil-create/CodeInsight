#include <bits/stdc++.h>

using namespace std;
long long a, b;
int n;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a >> b;
        if(a > b){
            swap(a, b);
        }
        if(a == b){
            cout << max(a * 2 - 2, 0ll) << '\n';
        }
        else if(a + 1 == b){
            cout << max(2 * a - 2, 0ll) << '\n';
        }
        else{
            long long c, l = 0, r = 1e9;
            while(r - l > 1){
                long long mid = (r + l) / 2;
                if(mid * mid < a * b){
                    l = mid;
                }
                else{
                    r = mid;
                }
            }
            if(r * r < a * b){
                c = r;
            }
            else{
                c = l;
            }
            if(c * (c + 1) < a * b){
               cout << max(2 * c - 1, 0ll) << '\n';
            }
            else{
                cout << max(2 * c - 2, 0ll) << '\n';
            }
        }
    }
}
