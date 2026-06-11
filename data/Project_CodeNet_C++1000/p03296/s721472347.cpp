#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int N;
    cin >> N;
    vector<int> a(N+1,0);
    rep(i, N){
        cin >> a[i];
    }
    int s = 0;
    int ans = 0;
    rep(i, N){
        if(a[i] == a[i+1]){
            s++;
        }else{
            ans += (s+1)/2;
            s = 0;
        }
    }
    cout << ans << endl;
return 0;}