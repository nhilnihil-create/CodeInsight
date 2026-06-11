#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;

typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int MAX = 100010;
int main() {
    vector<int>is_prime(MAX,1);
    is_prime[0] = 0;
    is_prime[1] = 0;
    for(int i = 2;i<=100000;i++) {
        if(is_prime[i] == 0) continue;
        for(int j = i*2; j<=100000;j += i) {
            is_prime[j] = 0;
        }
    }

    vector<int>a(MAX,0);
    for(int i = 1;i<=100000;i++) {
        if((i+1)%2 == 1) continue;
        if(is_prime[i] && is_prime[(i+1)/2]) a[i] = 1;
    }
    
    vector<int>s(MAX,0);
    for(int i = 0;i<=100000;i++) {
        s[i+1] = s[i] + a[i+1];
    }
    
    int q;
    cin >> q;
    rep(i,q) {
        int l,r;
        cin >> l >> r;
        cout << s[r] - s[l-1] << endl;
    }
}