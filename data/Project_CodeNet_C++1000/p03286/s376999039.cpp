#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    string s = "";
    while(N != 0){
        if(N % -2 == 0){
            s = "0" + s;
        } else {
            s = "1" + s;
            N--;
        }
        N /= -2;
    }
    if(s == ""){
        s = "0";
    }

    cout << s << endl;

    return 0;
}