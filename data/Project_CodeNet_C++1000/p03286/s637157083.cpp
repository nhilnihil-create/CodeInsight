#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


string ans;

int main(){
    long long n;
    cin >> n;

    while(n != 0){
        long long r = n % 2;
        if(r < 0) r += 2;

        n = (n-r)/(-2);
        ans += ('0'+r);
    }

    reverse(ans.begin(), ans.end());

    if(ans == ""){
        ans = "0";
    }

    cout << ans << endl;
    return 0;
}