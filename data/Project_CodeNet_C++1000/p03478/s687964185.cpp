#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0;
    rep(i, n){
        int tmp = i+1;
        int sum = 0;
        while(tmp > 0){
            sum += tmp % 10;
            tmp /= 10;
        }
        if(sum >= a && sum <= b) ans += i + 1;
    }

    cout << ans << endl;
    return 0;
}