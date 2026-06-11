#include <bits/stdc++.h>
 
using namespace std;
 
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i<  n; i++)
 
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
 
const long long INF = 1LL << 60;
#define PI 3.14159265359 
long long MOD = 1000000007;


template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}
 
int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}
 
long long lcm (int a, int b){
    return  (long long) a*b /gcd(a,b);
}

long long GCD(long long a, long long b) { return b ? GCD(b, a%b) : a; }

long long dp[200100];

int main(){
    string S;
    cin >> S;

    int ans = 9999;
    int x =0;

    rep(i,S.length()-2){
           int a = S[i]-'0';
           int b = S[i+1]-'0';
           int c = S[i+2]-'0'; 

           x = 100*a + 10*b +c;
           ans = min(abs(753-x),ans);
    }

    cout << ans << endl;

}

