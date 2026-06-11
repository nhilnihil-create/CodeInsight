#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

const int mod = 1e9+7;
#define ll long long int
const double epsilon = 1e-7;

ll mi(ll x, ll y){
    if(x<y)return x;
    return y;
}
char s[200001];
char t[200001];
int lout[200001];
int rout[200001];
int uout[200001];
int dout[200001];
int main(void){
    int h, w, n;
    scanf("%d %d %d", &h, &w, &n);
    int sr, sc;
    scanf("%d %d", &sr, &sc);
    sr--;
    sc--;
    scanf("%s", &s);
    scanf("%s", &t);
    if(s[n-1] == 'L'){
        lout[n-1] = 0;
        rout[n-1] = w;
        uout[n-1] = -1;
        dout[n-1] = h;
    }
    if(s[n-1] == 'R'){
        lout[n-1] = -1;
        rout[n-1] = w-1;
        uout[n-1] = -1;
        dout[n-1] = h;
    }
    if(s[n-1] == 'U'){
        lout[n-1] = -1;
        rout[n-1] = w;
        uout[n-1] = 0;
        dout[n-1] = h;
    }
    if(s[n-1] == 'D'){
        lout[n-1] = -1;
        rout[n-1] = w;
        uout[n-1] = -1;
        dout[n-1] = h-1;
    }
    for(int i = n - 2;i >= 0;i--){
        if(t[i] == 'L'){
            lout[i] = lout[i+1];
            rout[i] = rout[i+1]+1;
            uout[i] = uout[i+1];
            dout[i] = dout[i+1];
        }
        if(t[i] == 'R'){
            lout[i] = lout[i+1]-1;
            rout[i] = rout[i+1];
            uout[i] = uout[i+1];
            dout[i] = dout[i+1];
        }
        if(t[i] == 'U'){
            lout[i] = lout[i+1];
            rout[i] = rout[i+1];
            uout[i] = uout[i+1];
            dout[i] = dout[i+1]+1;
        }
        if(t[i] == 'D'){
            lout[i] = lout[i+1];
            rout[i] = rout[i+1];
            uout[i] = uout[i+1]-1;
            dout[i] = dout[i+1];
        }
        
        if(lout[i] == -2)lout[i]++;
        if(rout[i] == w+1)rout[i]--;
        if(uout[i] == -2)uout[i]++;
        if(dout[i] == h+1)dout[i]--;
        
        if(s[i] == 'L'){
            lout[i]++;
        }
        if(s[i] == 'R'){
            rout[i]--;
        }
        if(s[i] == 'U'){
            uout[i]++;
        }
        if(s[i] == 'D'){
            dout[i]--;
        }
        if(lout[i] == w-1 || rout[i] == 0 || uout[i] == h-1 || dout == 0){
            printf("NO\n");
            return 0;
        }
    }
    //for(int i = 0;i < n;i++)printf("%d %d %d %d\n", lout[i], rout[i], uout[i], dout[i]);
    if(sc > lout[0] && sc < rout[0] && sr > uout[0] && sr < dout[0])printf("YES\n");
    else printf("NO\n");
    return 0;
}
