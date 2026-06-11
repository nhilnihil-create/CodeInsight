#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;
typedef pair<Int,Int> p;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if(abs(a-b) <= d && abs(b-c) <= d){
        cout << "Yes" << endl;
    } else if (abs(a-c) <= d){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
