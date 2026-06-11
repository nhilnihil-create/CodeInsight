#include<bits/stdc++.h>
using namespace std;
#define int long long
inline void read(int &x){
    char c = getchar();
    int p = 1;
    x = 0;
    while(!isdigit(c)){
        if(c == '-')p = -1;
        c = getchar();
    }
    while(isdigit(c)){
        x = (x << 1) + (x << 3) + (c ^ '0');
        c = getchar();
    }
    x *= p;
}
int t, a, b, c, d;
signed main(){
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    read(t);
    while(t--){
        read(a), read(b), read(c), read(d);
        if(a < b){puts("No"); continue;}
        if(d < b){puts("No"); continue;}
        if(b <= c + 1){puts("Yes"); continue;}
        int gcd = __gcd(b, d);
        if(((a - c - 1ll) / gcd - (a - b) / gcd) > 0)puts("No");
        else puts("Yes");
    }
    return 0;
}