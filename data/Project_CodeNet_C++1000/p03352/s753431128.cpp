#include <bits/stdc++.h>

using namespace std;
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i<  n; i++)
 
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const long long INF = 1LL << 60;


int main () {
    int X;
    cin >> X;

    int ans =1;
    repr(i,1,X){
        repr(j,2,10){
            int num =i;
            rep(k,j-1){
                num *= i;
            }
            if(num <= X)ans = max(ans,num);
        }
    }

    cout << ans << endl;



}