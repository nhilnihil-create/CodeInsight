#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <set>
#include <stack>
#include <climits>
#include <cmath>

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define reps(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
const char sp = ' ';


using namespace std;

int main(void){
    ll H, W, N=0;
    ll a[600][600], b[600][600];
    cin>>H>>W;
    rep(i, H) rep(j, W) cin>>a[i][j], b[i][j]=a[i][j];
    rep(i, H) rep(j, W){
        if(b[i][j]%2==1 && j<W-1){
            N++;
            b[i][j]--;
            b[i][j+1]++;
        }
        if(b[i][j]%2==1 && i<H-1 && j==W-1){
            N++;
            b[i][j]--;
            b[i+1][j]++;
        }
    }
    cout<<N<<endl;
    rep(i, H) rep(j, W){
        if(a[i][j]%2==1 && j<W-1){
            cout<<i+1<<sp<<j+1<<sp<<i+1<<sp<<j+2<<endl;
            a[i][j]--;
            a[i][j+1]++;
        }
        if(a[i][j]%2==1 && i<H-1 && j==W-1){
            cout<<i+1<<sp<<j+1<<sp<<i+2<<sp<<j+1<<endl;
            a[i][j]--;
            a[i+1][j]++;
        }
    }
    return 0;
}
