#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;
#define reverse(s) reverse(s.begin(),s.end())

int main(){
    int n,m;
    cin >> n >> m;

    map<int,int> a;
    rep(i,m)    a[i];
    rep(i,n){
        int k;  cin >> k;
        rep(i,k){
            int A;  cin >> A;
            A--;
            a[A]++;
        }
    }

    int ans(0);
    rep(i,m){
        if(a[i]==n){
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}