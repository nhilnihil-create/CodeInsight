#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int h,w;cin>>h>>w;
    int a[h][w];
    rep(i,h){
        string s;cin>>s;
        rep(j,w){
            if(s[j]=='#')a[i][j]=1;
            else a[i][j]=0;
        }
    }
    rep(i,h)rep(j,w){
        if(a[i][j]==1){
            if(a[i-1][j]==0 && a[i+1][j]==0 && a[i][j-1]==0 && a[i][j+1]==0){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;    
	return 0;
}