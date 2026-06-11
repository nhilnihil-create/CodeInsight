#include <iostream>
using namespace std;


int cnt(int n){
    int rtn = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0) rtn++;
    }
    return rtn;
}

int main(){
    int n, ans = 0;
    cin >> n;

    for (int i = 1; i <= n; i++){
        if(i % 2 == 1){
            if(cnt(i) == 8) ans++;
            }
    }
    
    cout << ans << endl;

}