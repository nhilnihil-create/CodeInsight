#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

int main(){
    int h,w,n;
    scanf("%d%d%d",&h,&w,&n);
    int r,c;
    scanf("%d%d",&r,&c);
    --r;--c;
    string s,t;
    cin >> s >> t;
    bool out = false;
    int y=r,x=c;
    rep(j,4){
        rep(i,n){
            if(s[i]=='R') ++x;
            else if(s[i]=='U') --y;

            if(y<0||x>=w) out=true;

            if(t[i]=='L'&&x>0) --x;
            else if(t[i]=='D'&&y<h-1) ++y;
        }
        rep(i,n){
            if(s[i]=='R') s[i]='D';
            else if(s[i]=='D') s[i]='L';
            else if(s[i]=='L') s[i]='U';
            else if(s[i]=='U') s[i]='R';

            if(t[i]=='R') t[i]='D';
            else if(t[i]=='D') t[i]='L';
            else if(t[i]=='L') t[i]='U';
            else if(t[i]=='U') t[i]='R';
        }
        int tmp=r;
        r=c;
        c=h-1-tmp;
        swap(h,w);
        y=r;
        x=c;
        //cout << r << " " << c << endl;
    }
    cout << (out?"NO":"YES") << endl;
    return 0;
}