#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin >>n;
    vector<int> c(n),s(n),f(n);
    rep(i,n-1) cin >> c[i+1] >> s[i+1] >> f[i+1];
    for(int i = 1;i<=n-1;i++){
        int temp = s[i]+c[i];
        for(int j = i+1;j<=n-1;j++){
            if(temp<s[j]) temp = s[j]+c[j];
            else if(temp%f[j]==0) temp = temp+c[j];
            else temp = (temp/f[j])*f[j] + f[j] + c[j];
        }
        cout << temp << endl;
    }
    cout << 0 << endl;
}
