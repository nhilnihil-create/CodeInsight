#include <cmath>
#include <cstdlib>
#include <iostream>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <chrono>
#include <random>
#include <tuple>
#include <utility>
#include <fstream>
#include <complex>

const long INF = (1l << 30);
const long LINF = (1l << 60);

const long LEN = 1000005;

long n;
std::string s;
long q;

long d[LEN], m[LEN], c[LEN], dm[LEN], mc[LEN], dmc[LEN];

long seg_anscal(long a, long b){
    return dmc[b] - dmc[a] - d[a]*(mc[b] - mc[a]) - dm[a]*(c[b] - c[a]);
}

long ans_cal(long k){
    long res = 0;
    for(long i = 0; i < n; i++){
        long r = i+1;
        long l = std::max(0l, i-k+1);
        if(s[i] == 'C'){
            res += dm[r] - dm[l] - d[l]*(m[r]-m[l]);
        }
    }
    return res;
}

int main(){
    scanf("%ld", &n);
    std::cin >> s;
    for(int i = 0; i < n; i++){
        d[i+1] = d[i];
        if(s[i] == 'D'){
            d[i+1]++;
        }
        m[i+1] = m[i];
        if(s[i] == 'M'){
            m[i+1]++;
        }
        c[i+1] = c[i];
        if(s[i] == 'C'){
            c[i+1]++;
        }
    }
    for(int i = 0; i < n; i++){
        dm[i+1] = dm[i];
        if(s[i] == 'M'){
            dm[i+1] += d[i];
        }
        mc[i+1] = mc[i];
        if(s[i] == 'C'){
            mc[i+1] += m[i];
        }
    }
    for(int i = 0; i < n; i++){
        dmc[i+1] = dmc[i];
        if(s[i] == 'C'){
            dmc[i+1] += dm[i];
        }
    }

    /*
    printf("   ");
    for(int i = 0; i <= n; i++){
        printf("%2d ", i);
    }
    printf("\n");
    printf("D   ");
    for(int i = 0; i <= n; i++){
        printf("%2ld ", d[i]);
    }
    printf("\n");
    printf("M   ");
    for(int i = 0; i <= n; i++){
        printf("%2ld ", m[i]);
    }
    printf("\nC   ");
    for(int i = 0; i <= n; i++){
        printf("%2ld ", c[i]);
    }
    printf("\nDM  ");
    for(int i = 0; i <= n; i++){
        printf("%2ld ", dm[i]);
    }
    printf("\nMC  ");
    for(int i = 0; i <= n; i++){
        printf("%2ld ", mc[i]);
    }
    printf("\nDMC ");
    for(int i = 0; i <= n; i++){
        printf("%2ld ", dmc[i]);
    }
    printf("\n");
    //*/

    scanf("%ld", &q);
    for(int i = 0; i < q; i++){
        long k;
        scanf("%ld", &k);
        printf("%ld\n", ans_cal(k));
    }
    return 0;
}
