#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
template<typename T>
void print(T x) {
    cout << x << endl;
}
int main(void) {
    int a,b,c; cin >> a >> b >> c;
    if(b<a) swap(a,b);
    if(a<c && c<b) print("Yes");
    else print("No");
}
