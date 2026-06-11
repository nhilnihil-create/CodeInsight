#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int h,w;cin>>h>>w;
    int a[h][w];rep(i,h)rep(j,w)a[i][j]=0;
    rep(i,h){
        string s;cin>>s;
        rep(j,w)if(s[j]=='#'){
            a[i][j]=-100;
            rep(k,3)rep(l,3){
              if(i-1+k>=0 && i-1+k<h && j-1+l>=0 && j-1+l<w) ++a[i-1+k][j-1+l];
            }
        }
    }
    rep(i,h){
        rep(j,w){
        if(a[i][j]<0)cout<<'#';
        else cout<<a[i][j];
        }
        cout<<endl;
    }
	return 0;
}