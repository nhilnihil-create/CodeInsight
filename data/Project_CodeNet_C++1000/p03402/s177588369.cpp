#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define MOD 1000000007
#define INF (1<<30)
#define LINF (1LL<<60)
#define endl "\n"
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(int (i)=(n-1);(i)>=0;(i)--)
#define Flag(x) (1<<(x))
#define Flagcount(x) __builtin_popcount(x)
#define pint pair<int,int>
#define pdouble pair<double,double>
typedef unsigned long long int ull;
typedef long long lint;
 
int main(void){
    int A,B;
    cin >> A >> B;
    int h1=3*ceil((double)A/50),h2=3*ceil((double)B/50),w=100;
    A--,B--;
    bool ans1[h1][100]={};
    bool ans2[h2][100]={};
    for(int i=0;i<h1;i++){
        if(i%3==0 || i%3==2) rep(j,100) ans1[i][j]=1;
        else{
            rep(j,100){
                if(j%2==1) ans1[i][j]=1; 
            }
        }
    }
    for(int i=0;i<h2;i++){
        if(i%3==1) rep(j,100) if(j%2==0) ans2[i][j]=1;
    }
    int Acount=(h1/3)*50,Bcount=(h2/3)*50;
    int Ap=0,Bp=0;
    while(Acount!=A){
        Acount--;
        ans1[1][Ap]=1;
        Ap+=2;
    }
    while(Bcount!=B){
        Bcount--;
        ans2[1][Bp]=0;
        Bp+=2;
    }
    cout << h1+h2 << " " << 100 << endl;
    rep(i,h1){
        rep(j,100){
            if(ans1[i][j]==0) cout << '.';
            else cout << '#';
        }
        cout << endl;
    }
    rep(i,h2){
        rep(j,100){
            if(ans2[i][j]==0) cout << '.';
            else cout << '#';
        }
        cout << endl;
    }
}