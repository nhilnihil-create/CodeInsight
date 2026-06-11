#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(){
    int n; cin>>n;
    int sum=0, maxp=0, p;
    rep(i,n){
        cin>>p;
        sum += p;
        maxp = max(maxp, p);
    }
    cout << sum -maxp/2 << endl;
    return 0;
}