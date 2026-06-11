#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#define MAXN 200005
#define PLI pair<long long,int>
#define fi first
#define se second
#define mp make_pair
#define ha 99994711
#define ba 823
//#define ivorysi
using namespace std;
typedef long long int64;
int N;
char s[305][305],b[305][305];
int64 hc[305],hr[305],e;
inline int C(int x) {
    return x > N ? x - N : x;
}
bool check(int y) {
    int T = C(N + y);
    for(int i = 1 ; i <= N ; ++i) 
        hr[i] = (hr[i] * ba + (b[i][T] - 'a' + 1)) % ha;
    for(int i = 1 ; i <= N ; ++i) {
        if(hr[i] != hc[C(i + y)]) {
            T = C(N + y + 1);
            for(int j = 1 ; j <= N ; ++j) 
                hr[j] = (hr[j] - e * (b[j][T] - 'a' + 1) % ha + ha) % ha;
            return false;
        }
    }
    T = C(N + y + 1);
    for(int i = 1 ; i <= N ; ++i) 
        hr[i] = (hr[i] - e * (b[i][T] - 'a' + 1) % ha + ha) % ha;
    return true;
}
void Solve() {
    scanf("%d",&N);
    if(N == 1) {
        puts("1");return;
    }
    e = 1;
    for(int i = 1 ; i < N ; ++i) e = e * ba % ha;
    for(int i = 1 ; i <= N ; ++i) {
        scanf("%s",s[i] + 1);
    }
    int cnt = 0;
    for(int A = 0 ; A < N ; ++A) {
        memset(hc,0,sizeof(hc));
        memset(hr,0,sizeof(hr));
        for(int i = 1 ; i <= N ; ++i) {
            for(int j = 1 ; j <= N ; ++j) {
                b[i][j] = s[C(i + A)][j];
                hc[j] = (hc[j] * ba + (b[i][j] - 'a' + 1)) % ha;
                if(j != N) {
                    hr[i] = (hr[i] * ba + (b[i][j] - 'a' + 1)) % ha;
                }
            }
        }
        for(int B = 0 ; B < N ; ++B) {
            if(check(B)) ++cnt;
        }
    }
    printf("%d\n",cnt);
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}