#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
typedef pair<int,int> PP;
typedef long long ll;
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE cout << -1 << endl;return 0
#define Endl endl

int K,k=0;

int out(int R){
    cout << R << endl;
    k++;
    if(k>=K){
        return -1;
    }else{
        return 0;
    }
}


signed main(void){
    cin >> K;
    
    int s=1,t=9,u=1;
    REP(l,3){
        for(int i=s;i<=t;i+=u){
            if(out(i)==-1){
                return 0;
            }
        }
        s=s*10+9;
        t=t*10+9;
        u=10*u;
    }
    
    int r=99;
    int i=20;
    while(1){
        i=min(i,100LL);
        for(int j=10;j<i;j++){
            cout << j;
            if(out(r)==-1){
                return 0;
            }
        }
        for(int j=i+9;j<=99;j+=10){
            cout << j;
            if(out(r)==-1){
                return 0;
            }
        }
        i+=10;
        if(log10(r)>=11)break;
        r=r*10+9;
    }
    for(int j=100;j<=108;j++){
        cout << j;
        if(out(r)==-1){
            return 0;
        }
    }
    r=r*10+9;
    
    for(int j=10;j<=99;j++){
        cout << j;
        if(out(r)==-1){
            return 0;
        }
    }
    
    
    return 0;
}

/* 考察につかったコード　いちおう残すくにきあ
int S(int x){
    int r=0;
    while(x){
        r+=x%10;
        x/=10;
    }
    return r;
}

signed main(void){
    setdouble(10);
    int K;
    cin >> K;
    int mx1=1000000000000,mx2=1;
    for(int j=1e6;j>0;j--){
        int i=(j+1)*100000000-1;
        //cout << i << " "<<(double)((i+0.0)/(double)S(i)) << endl;
        if(i*mx2<=mx1*S(i)){
            //cout << i << " "<<(double)((i+0.0)/(double)S(i)) << endl;
            cout << i << endl;
            mx1=i;
            mx2=S(i);
        }
    }
    
    
    return 0;
}*/
