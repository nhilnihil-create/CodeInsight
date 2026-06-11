#include "bits/stdc++.h"
 
typedef long long ll;
#define int ll
#define fi first
#define se second
#define SORT(a) sort(a.begin(),a.end())
#define rep(i,n) for(int i = 0;i < (n) ; i++) 
#define REP(i,n) for(int i = 0;i < (n) ; i++) 
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define INF LLONG_MAX/2
 
using namespace std;
int MOD = 1000000007;
int gcd(int a,int b){
    if(a < b){
        int c = a;
        a = b;
        b = c;
    }
    if(a%b == 0) return b;
    else return gcd(b,a%b);
}
signed main(){

    int n;
    cin >> n;
    if(n == 3){
        cout << 2 << " " << 5 << " " << 63 << endl;
        return 0;
    }else if(n == 4){
        cout << 2 << " " << 5 << " " << 20 << " " << 63 << endl;
        return 0;
    }else if(n == 5){
        cout << 2 << " " << 3 << " " << 4 << " " << 6 << " " << 9 << endl;
        return 0;
    }else if(n == 6){
        cout << 2 << " " << 3 << " " << 4 << " " << 8 << " " << 9 << " " << 10 << endl;
        return 0;
    }else if(n == 7){
        cout << 6 << " " << 2 << " " << 3 << " " << 4 << " " << 8 << " " << 9 << " " << 10 << endl;
        return 0;
    }
    int x = n/8;
    rep(i,x){
        cout << 12*i+2 << " ";
        cout << 12*i+3 << " ";
        cout << 12*i+4 << " ";
        cout << 12*i+6 << " ";
        cout << 12*i+8 << " ";
        cout << 12*i+9 << " ";
        cout << 12*i+10 << " ";
        cout << 12*i+12 << " ";
    }
    if(n%8 == 1){
        cout << 12*x+6 << " ";
    }else if(n%8 == 2){
        cout << 12*x+2 << " ";
        cout << 12*x+4 << " ";        
    }else if(n%8 == 3){
        cout << 12*x+2 << " ";
        cout << 12*x+4 << " ";        
        cout << 12*x+6 << " ";        
    }else if(n%8 == 4){
        cout << 12*x+2 << " ";
        cout << 12*x+4 << " ";        
        cout << 12*x+3 << " ";        
        cout << 12*x+9 << " ";        
    }else if(n%8 == 5){
        cout << 12*x+2 << " ";
        cout << 12*x+4 << " ";        
        cout << 12*x+3 << " ";        
        cout << 12*x+9 << " ";        
        cout << 12*x+6 << " ";        
    }else if(n%8 == 6){
        cout << 12*x+2 << " ";
        cout << 12*x+4 << " ";        
        cout << 12*x+3 << " ";        
        cout << 12*x+9 << " ";       
        cout << 12*x+8 << " ";       
        cout << 12*x+10 << " ";       
    }else if(n%8 == 7){
        cout << 12*x+2 << " ";
        cout << 12*x+4 << " ";        
        cout << 12*x+3 << " ";        
        cout << 12*x+9 << " ";       
        cout << 12*x+8 << " ";       
        cout << 12*x+10 << " ";       
        cout << 12*x+6 << " ";       
    }


    return 0;   
}
// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl https://ddcc2019-final.contest.atcoder.jp/tasks/ddcc2019_final_a
// rm -r -f test;oj dl http://arc096.contest.atcoder.jp/tasks/arc096_b
