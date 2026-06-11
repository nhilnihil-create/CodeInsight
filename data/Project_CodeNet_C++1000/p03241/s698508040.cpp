#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n,m;
    cin >> n >> m;
    int hoge = (int) m / n;
    int ans = 1;
    for(int i = hoge; i >= 1; i--){
        if(m % i == 0){
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}