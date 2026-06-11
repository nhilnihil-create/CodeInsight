#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    int n;
    cin >>n;
    int zentai=1,cnt=0;
    vector<int>a(n);
    rep(i,n){
        cin >> a[i];
        if(a[i] % 2 ==  0)cnt++;
    }
    cnt = pow(2,cnt);
    
    rep(i,n) zentai *= 3;
    cout << zentai - cnt << endl;
    
}