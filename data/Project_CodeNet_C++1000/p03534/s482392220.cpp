#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    std::cin >> s;
    ll a,b,c;
    a = b= c = 0;
    for (int i = 0; i < s.length(); i++) {
        if(s[i] == 'a'){
            a++;
        }else if(s[i]=='b'){
            b++;
        }else{
            c++;
        }
    }
    ll m = min({a,b,c});
    // a,b,c,a,b,c,a,b,c,みたいになりそう
    if(a-m>= 2 || b-m>= 2 || c-m >= 2){
        std::cout << "NO" << std::endl;
    }else{
        std::cout << "YES" << std::endl;
    }
}
