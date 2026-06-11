#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
int mod = 1000000007;
#define ll long long



int main() {
    int n;
    cin>>n;
    rep(i,100)rep(j,100){
        if(i*4+j*7==n){
            cout << "Yes" <<endl;
            return 0;
        }
    }
    cout << "No" <<endl;
    return 0;
}