using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i = 0; i < (n); i++)
#define divup(a,b) ( ( (a) + ( (b) - 1u) ) / (b) ) // a/b の余り切り上げ
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
ll mod = 1000000007;
ll mod9 = 1000000009;

signed main(){
    ll h,w;
    cin>>h>>w;
    char s[55][55];
    rep(i,h+2){
        s[0][i]='.';
        s[w+1][i]='.';
    }
    rep(i,w+2){
        s[i][0]='.';
        s[i][h+1]='.';
    }
    //printf("\n%s\n",s[h+1]);
    rep(i,h){
        scanf("%s",s[i+1]+1);
        strcat(s[i+1],".");
    }
    bool f_field=0;
    //rep(i,h+2) printf("%s\n",s[i]);
    ll ix[4] = {1,0,-1,0};
    ll jy[4] = {0,1,0,-1};
    rep(i,h) rep(j,w){
        if(s[i+1][j+1]=='#'){        
            bool ff=0;
            rep(k,4){
                if(s[i+1+ix[k]][j+1+jy[k]]=='#') ff=1;
            }
            if(!ff) f_field=1;
        }
    }
    if(f_field) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}
