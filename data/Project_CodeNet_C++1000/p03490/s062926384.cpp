#include <bits/stdc++.h>
using namespace std;

const int N = 8005;

int n, x, y, vv[2 * N], *v, c, d;
char s[N];
vector<int> xv, yv;

int main(){
    v = vv + N;
    scanf("%s%d%d", s, &x, &y);
    n = strlen(s);
    int i = 0;
    for(; i < n; i++, x--) if(s[i] == 'T') break;
    xv.push_back(0);
    yv.push_back(0);
    for(int j; i < n; i = j){
        for(j = i + 1; j < n; j++) if(s[i] != s[j]) break;
        if(s[i] == 'T') d ^= (j - i) % 2;
        else{
            vector<int> nv, &cv = (d ? yv : xv);
            for(int k : cv){
                if(v[k - (j - i)] != i) nv.push_back(k - (j - i));
                if(v[k + (j - i)] != i) nv.push_back(k + (j - i));
                v[k - (j - i)] = v[k + (j - i)] = i;
            }
            cv = nv;
        }
    }
    puts(count(xv.begin(), xv.end(), x) && count(yv.begin(), yv.end(), y) ? "Yes" : "No");
}