#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
#define ll long long
const int inf = 1000000000;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);

    rep(i,n){
        cin >> a[i];
    }

    int ans = inf;

rep(i,n){
    int x=a[i];
    int cunt=0;
    while(x%2!=1){
       x=x/2;
        cunt++;
    }
    ans=min(ans,cunt);
}

cout << ans << endl;

}