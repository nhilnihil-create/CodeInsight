#include<iostream>
#include<set>
#include <bitset>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include <cstdio>
#include<algorithm>
#include <sstream>
#include<string>
#include<string.h>
#include <cmath>
#include <iomanip>
#include <string>
#include<list>
#include <limits>
#include <numeric>
#include <type_traits>
#define int long long
#define ll long long
#define mod  1000000007
#define inf 1e17
#define rep(i,j,n) for(int i=j;i<n;i++)
#define P pair<int,int>
double pi = 3.141592653589793;
using namespace std;
//ここから始めよう
bitset<20000> dpx;bitset<20000> dpy;
signed main(){
    string s;cin>>s;
    int x,y;cin>>x>>y;
    vector<int> dx,dy;
    int t=1;
    int cnt=0;
    rep(i,0,s.size()){
        if(s[i]=='F')cnt++;
        else {
            if(t)dx.push_back(cnt);
            else dy.push_back(cnt);
            cnt=0;
            t=t*-1+1;
        }
    }
    if(t)dx.push_back(cnt);
    else dy.push_back(cnt);
    dpx.set(10000+dx[0]);
    if(dx.size()>1)
    rep(i,1,dx.size()){
        dpx=(dpx<<dx[i])|(dpx>>dx[i]);
    }
    dpy.set(10000);
    if(dy.size())
    rep(i,0,dy.size()){
        dpy=(dpy<<dy[i])|(dpy>>dy[i]);
    }
    if(dpx[10000+x]&&dpy[10000+y])cout<<"Yes"<<endl;
    //else if(dpx[10000+x])cout<<"X"<<endl;
    //else if(dpy[10000+y])cout<<"Y"<<endl;
    else cout<<"No"<<endl;return 0;
}
