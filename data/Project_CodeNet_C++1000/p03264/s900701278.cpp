#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int k,a,b;
    cin>>k;
    if (k%2==0) {
        b=k/2;
        a=b;
    } else {
        b=k/2;
        a=b+1;
    }
    cout<<a*b<<endl;
}   
