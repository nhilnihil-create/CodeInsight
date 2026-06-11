#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int ans = 1;
    for(int i = 1; i*i <= m; i++){
        if(m % i == 0){
            int coans;
            if(i >= n && m/i >= n){
                coans = (i > m/i) ? i : m/i;
            }else if(i >= n){
                coans = m/i;
            }else if(m/i >= n){
                coans = i;
            }else{
                coans = 1;
            }
            if(ans < coans) ans = coans;
        }
    }
    cout << ans << endl;
    return 0;
}