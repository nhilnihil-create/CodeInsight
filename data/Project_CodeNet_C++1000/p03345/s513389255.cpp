#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
int64_t INF = 1000000007;

int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    int64_t a,b,c,k;
    cin >> a >> b >> c >> k;
    if(k%2==0){
        cout << a - b << endl;
    }else{
        cout << b - a << endl;
    }
    // a,bが交換しつつ、cだけ増えていく感じか
    // a = b+c;     b = a+c;     a-b=b-a;
    // a = a+c+c;   b = b+c+c;   a-b=a-b;
    // a = b+c+c+c; b = a+c+c+c; a-b=b-a;

}