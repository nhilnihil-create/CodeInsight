#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    int A,B;
    string S;
    cin >> A >> B >> S;
    bool ans = true;
    rep(i,A+B+1){
        if(i!=A) {
            int a = S[i]-'0';
            if(!(a>=0&&a<=9)) ans = false;
        } else {
            char s = S[i];
            if(s!='-') ans = false;
        } 
    }
    cout << (ans?"Yes":"No") << endl;
}
