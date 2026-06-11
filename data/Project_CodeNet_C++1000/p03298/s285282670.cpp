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
#define mp make_pair
string vec1, vec2;
map<pair<string, string>, int>ma;
char s[50];
int n, ans;
signed main(){
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    read(n);
    scanf("%s", s);
    int lim = 1 << n;
    for(register int i = 0; i < lim; ++i){
        vec1.clear(), vec2.clear();
        for(register int j = 0; j < n; ++j){
            if(1 & (i >> j))vec1.push_back(s[j]);
            else vec2.push_back(s[j]);
        }
        /*for(auto a : vec1){
            printf("%c", a);
        }
        puts("");*/
        ma[mp(vec1, vec2)]++;
    }
    for(register int i = 0; i < lim; ++i){
        vec1.clear(), vec2.clear();
        for(register int j = n - 1; j >= 0; --j){
            if(!(1 & (i >> j)))vec1.push_back(s[j + n]);
            else vec2.push_back(s[j + n]);
        }
        /*for(auto a : vec2){
            printf("%c", a);
        }
        puts("");*/
        ans += ma[mp(vec1, vec2)];
        //cout<<ma[vec2]<<endl;
    }
    printf("%lld\n", ans);
    return 0;
}