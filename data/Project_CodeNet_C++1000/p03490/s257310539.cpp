#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 100000000000000009
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define ZREP(i,n) for(int i=1;i<(n);++i)
#define YES(s) s?cout << "YES" << endl:cout << "NO" << endl
#define Yes(s) s?cout << "Yes" << endl:cout << "No" << endl
#define out(s,t,u) s?cout << t << endl:cout << u << endl
#define int ll
#define Endl endl


signed main(){
    int N,x,y;
    int dpx[2][114514]={};
    int dpy[2][114514]={};
    string S;
    cin >> S;
    cin >> x >> y;
    N=S.size();
    vector<int> X,Y;
    
    bool mode=0;//0ならX 1ならY
    int w=0;
    REP(i,N){
        if(S[i]=='F'){
            w++;
        }
        if(S[i]!='F' || i==N-1){
            if(mode==0){
                X.push_back(w);
                mode=1;
            }else{
                Y.push_back(w);
                mode=0;
            }
            w=0;
        }
    }
    x-=X[0];
    X[0]=0;
    
    //cout << x;REP(i,X.size()){cout <<" "<< X[i];}cout << endl;
    //cout << y;REP(i,Y.size()){cout <<" "<< Y[i];}cout << endl;
    
    REP(i,X.size()){
        x+=X[i];
        X[i]*=2;
    }
    REP(i,Y.size()){
        y+=Y[i];
        Y[i]*=2;
    }
    
    if(x<0 || y<0){
        cout << "No" << endl;
        return 0;
    }
    //cout << x;REP(i,X.size()){cout <<" "<< X[i];}cout << endl;
    //cout << y;REP(i,Y.size()){cout <<" "<< Y[i];}cout << endl;
    
    dpx[0][0]=1;
    dpy[0][0]=1;
    
    REP(j,X.size()){
        REP(i,19810){
            if(dpx[0][i]==1){
                dpx[1][i]=1;
                dpx[1][i+X[j]]=1;
            }
        }
        REP(i,19810){
            dpx[0][i]=dpx[1][i];
            dpx[1][i]=0;
        }
    }
    REP(j,Y.size()){
        REP(i,19810){
            if(dpy[0][i]==1){
                dpy[1][i]=1;
                dpy[1][i+Y[j]]=1;
            }
        }
        REP(i,19810){
            dpy[0][i]=dpy[1][i];
            dpy[1][i]=0;
        }
    }
    
    if(dpx[0][x]==1 && dpy[0][y]==1){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
    return 0;
}
