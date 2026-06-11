#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)


int main() {
    int n;
    int ans = 0;
    cin >> n;
    for(int i=1;i<n+1;i+=2){
        int temp;
        temp = 0;
        for(int j=1;j<i+1;j++){
            if(i%j==0)temp++;
        }
        if(temp==8)ans++;
    }
    cout << ans << endl;
}