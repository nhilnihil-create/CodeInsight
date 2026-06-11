#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<int> d(n);
    for(int i = 0; i < n; i++){
        cin >> d[i];
    }

    vector<int> num(110);
    for(int i = 0; i < n; i++){
        num[d[i]]++;
    }

    int ans = 0;
    for(int i = 1; i <= 100; i++){
        if(num[i] > 0) ans++;
    }
    cout << ans << endl;
    return 0;
}