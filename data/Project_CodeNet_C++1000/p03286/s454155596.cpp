#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> s;

    if(n==0){
        cout << "0" << "\n";
        return 0;
    }

    int bin=-2;
    while(n!=0) {
        int m=n%(-2);
        if(m<0) m+=2;
        s.emplace_back(m);
        n=(n-m)/(-2);
    }

    n=s.size();
    for(int i = 0; i < n; i++) {
        cout << (s[n-1-i]!=0 ? 1 : 0);
    }
    cout << "\n";

    return 0;
}