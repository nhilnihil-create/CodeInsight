#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
//#define INF 810114514
//#define PI 3.141592653589
typedef pair<int,int> PP;
typedef long long ll;
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE do { cout << "0" << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl

long long gcd(long long a,long long b){
    a=std::abs(a);
    b=std::abs(b);
    if(a>b)std::swap(a,b);
    if(a==0){
        return b;
    }
    
    long long r=a%b;
    while(r){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

signed main(void){
    int T;
    cin >> T;
    REP(_,T){
        int A,B,C,D;
        cin >> A >> B >> C >> D;
        if(A<B){cout << "No" << endl;continue;}
        if(D<B){cout << "No" << endl;continue;}
        if(C>=B){cout << "Yes" << endl;continue;}
        int g = gcd(B,D);
        int h = B - g + (A%g);
        if(h>C){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }
    return 0;
}

