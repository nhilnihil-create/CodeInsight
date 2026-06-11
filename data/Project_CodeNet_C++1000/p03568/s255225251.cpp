#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
using ll = long long;

int main() {
    int n, count = 1;
    cin >> n;
    rep(i, 0, n){
        int c;
        cin >> c;
        if(c % 2 == 1) count *= 1;
        else count *= 2;
    }
    cout << pow(3, n) - count << endl; 
}