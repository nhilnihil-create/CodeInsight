#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define se second
#define pi 2*acos(0)
#define PI 3.14159265358979323846264338

typedef long long ll;
typedef unsigned long long ull;
typedef pair < int , int > pii;
typedef pair < ll , ll > pll;

const int N = 100010;
const int MX = 123456;
const int mod = (int)1e9 + 7;
const int base = 1023456789;
const ull BS1 = 10000019ULL;
const int INF = (1 << 29);

template < class T > inline void fastScan(T &x){
    register char c = getchar();
    int neg = 0; x = 0;
    for(   ; (c < 48 || c > 57) && (c != '-'); c = getchar());
    if(c == '-') { neg = 1; c = getchar(); }
    for(   ; c > 47 && c < 58; c = getchar()){
        x = (x << 1) + (x << 3) + c - 48;
    }
    if(neg) x = -x;
}

int n;
int inp[N];

int ans[1234][1234];

int main(){
    fastScan(n);
    if(n == 1){
        puts("Yes");
        puts("2");
        puts("1 1");
        puts("1 1");
        return 0;
    }
    int flag = 0, col = 0, r, c;
    for(int i = 2; i <= 10000; i++){
        if((i * (i + 1)) / 2 == n){
            flag = 1;
            col = i;
            r = i + 1; c = i;
            break;
        }
    }
    if(flag == 0){
        puts("No");
        return 0;
    }
    int x = 1, y = 1, nn = 1;
    while(nn <= n){
        for(int i = y, j = nn; i <= y + col - 1; i++, j++){
            ans[x][i] = j;
        }
        for(int i = x + 1, j = nn; i <= x + col; i++, j++){
            ans[i][y] = j;
            nn++;
        }
        col--;
        x++; y++;
    }
    puts("Yes");
    printf("%d\n", r);
    for(int i = 1; i <= r; i++){
        printf("%d", c);
        for(int j = 1; j <= c; j++){
            printf(" %d", ans[i][j]);
        }
        puts("");
    }
    return 0;
}
