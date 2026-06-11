#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<=(int)(n);i++)
#define ll long long

int main(){
    int n,a;
    cin >> n >> a;
    string ans="No";
    rep(j,n/500+2){
        rep(i,a){
            //cout << i+500*j <<endl;
            if(n==i+500*j){
                ans="Yes";
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}