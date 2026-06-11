#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    int n,ans=1;
    cin >> n;
    rep(i,n){
        int a;
        cin >> a;
        if(a%2==0) ans *= 2;
    }
    cout << pow(3,n)-ans << endl;
}