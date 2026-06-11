#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

string s;

lli q3n(lli x, lli n){
    while(n--) x/=3;
    return x;
}

int main(void){
    cin >> s;
    lli ans = 0;
    for(int d = 3; d <= s.size(); d++){
        string t(d, '0');
        rep(j, pow(3, d)){
            int a, b, c;
            a = b = c = 0;
            rep(k, d){
                int r = q3n(j, k)%3;
                if(r == 0){
                    t[k] = '3';
                    a++;
                }else if(r == 1){
                    t[k] = '5';
                    b++;
                }else{
                    t[k] = '7';
                    c++;
                }
            }
            if(a > 0 && b > 0 && c > 0 && stoll(t) <= stoll(s)){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
