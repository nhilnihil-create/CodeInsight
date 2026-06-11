#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<math.h>

#define rep(i,a,n) for(int (i)=(a);(i)<(n);(i)++)
#define rrep(i,a,n) for(int (i)=(a);(i)>=(n);(i)--)

#define INF ll 1 << 60
#define MOD 1000000007

typedef  long long ll;

using namespace std;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int gcd(long long int a,long long int b){
    long long int r;
    if(a < b){
        int tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
    while(r = a % b){
        a = b;
        b = r;
    }
    return a;
}

void Integer_factorization(long long int b,long long int n){
    long long int a = 2;
    long long int count = 0;
    long long int ans = 1;
    long long int ndash = n;
    if(b == 1) cout << n << endl;
    else{
    while(ndash >= a*a){
        if(n % a  == 0){
            count++;
            n/=a;

        if(count % b == 0){
            ans *= a;
        }
        }else{a++;count = 0;}
    }

    cout<<  ans << endl;
    }
}

void ys(){
    cout << "Yes" << endl;
}

void yb(){
    cout << "YES" << endl;
}

void ns(){
    cout << "No" << endl;
}

void nb(){
    cout << "NO" << endl;
}

int dig(int d){
    int ans = 1;
    if(d == 0) return ans;
    while(d != 0){
        d--;
        ans*=100;
    }
    return ans;
}
int c['z'+1];

void solve(void){
    int n,k;
    cin >> n >> k;
    cout << n-k+1;   
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}