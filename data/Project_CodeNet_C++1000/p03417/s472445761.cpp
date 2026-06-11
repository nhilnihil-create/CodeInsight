#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    if(n > m){
        int tmp = n;
        n = m;
        m = tmp;
    }

    long long int ans = 0;
    if(n == 1){
        if(m == 1) ans = 1;
        else if(m >= 3) ans = m-2;
    }else if(n == 2){
        ans = 0;
    }else{
        ans = (long long int)(m-2)*(n-2);
    }
    cout << ans << endl;
    return 0;
}