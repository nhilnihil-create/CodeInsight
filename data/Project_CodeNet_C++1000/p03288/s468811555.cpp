#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    int n;
    cin >> n;
    if(n < 1200) {
        cout << "ABC" << endl;
        return 0;
    }
    else if(n < 2800) {
        cout << "ARC" << endl;
        return 0;
    }
    cout << "AGC" << endl;
}