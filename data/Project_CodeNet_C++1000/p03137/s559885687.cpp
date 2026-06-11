#include <bits/stdc++.h>
 
using namespace std;
 
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i<  n; i++)
 
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
 
const long long INF = 1LL << 60;
#define PI 3.14159265359 
 
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

int main(){
    int N, M;
    cin >> N >> M;

    vector<int>X(M);
    vector<long long>kyori(M-1);
    rep(i,M)cin>> X[i] ;
    sort(X.begin(),X.end());
    rep(i,M-1)kyori[i] = X[i+1]-X[i];
    sort(kyori.begin(),kyori.end(),greater<int>());

    long long ans = 0;
    for(int i = N-1; i<M-1; i++){
        ans += kyori[i];
    }

    cout << ans << endl;

}

