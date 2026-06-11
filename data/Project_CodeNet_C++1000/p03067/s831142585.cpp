#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    if(a > b) {
        swap(a,b);
    }
    if(a <= c && c <= b) {
        puts("Yes");
    } else {
        puts("No");
    }
    return 0;
}