#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main(){
    int n;
    cin >> n;
    int h[n];
    rep(i, n) cin >> h[i];
    int high_max = 0;
    rep(i, n) high_max = max(high_max, h[i]);
    bool cont;
    int cnt = 0;
    rep(i, high_max)
    {
        int top = high_max - i;
        cont = false;
        rep(j, n)
        {
            if(h[j]==top){
                if(!cont){
                    cnt++;
                    cont = true;
                }
                h[j]--;
            }else{
                cont = false;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}