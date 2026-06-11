#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    char x;
    cin >> x;
    char y;
    cin >> y;
    if(x > y) cout << ">" << endl;
    if(x == y) cout << "=" << endl;
    if(x < y) cout << "<" << endl;
}
