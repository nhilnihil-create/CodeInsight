#include <cstdio>
#include <functional>
#include <algorithm>
#include <vector>
#include <limits>
#include <numeric>
#include <type_traits>
#include <iostream>
#include <queue>
#include <math.h>
#include <bits/stdc++.h>
#include <queue>
#include <map>

using namespace std;

#define INF (1ll<<60)
#define INFint (1<<30)
#define MOD 1000000007
#define BOUND 27182818284

typedef long long ll;
typedef long long int lli;
typedef pair<int,int> P;

#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)

template<class T>
bool umax(T &a, const T &b){
    if (a<b) {
        a=b; return 1;
    }
    return 0;
}

template<class T>
bool umin(T &a, const T &b) {
    if (b<a) {
        a=b; return 1;
    }
    return 0;
}

// gcd
template<typename T>
T gcd(T a, T b){
    if(a==0)
        return b;
    return gcd(b%a,a);
}

// gcd array
int findGCD(int arr[], int n){
    int result = arr[0];
    for (int i=1; i < n; i++)
        result = gcd(arr[i], result);
    return result;
}

template<typename T>
T lcm( T m, T n ){
    // 引数に0がある場合は0を返す
    if ( ( 0 == m ) || ( 0 == n ) )
        return 0;
    return ((m/gcd(m, n)) * n); // lcm = m * n / gcd(m,n)
}

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    fill( (T*)array, (T*)(array+N), val );
}


int dx[5]={1,0,-1,0};
int dy[5]={0,1,0,-1};
// v.front() = -BOUND;
// v.back() = BOUND;

int N;
vector<double>t(200),v(200,0);
vector<double>r(200,0),l(200,0);

double func(double a){
    double minimum=100000;
    for(int i=0; i<N+2; i++) {
        if (a>=r[i]){
            minimum=min(minimum, a-r[i]+v[i]);
        }else if(a<=l[i]){
            minimum=min(minimum, l[i]-a+v[i]);
        }else{
            minimum=min(minimum,v[i]);
        }
    }
    return minimum;
}

int main(){
    double ans=0;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> t[i];
        l[i]=r[i-1];
        r[i]=l[i]+t[i];
    }

    for(int i=1; i<=N; i++){
        cin >> v[i];
    }
    l[N+1]=r[N+1]=r[N];
    for(double a=0; a<r[N];){
        ans+=0.25*(func(a)+func(a+0.5));
        a+=0.5;
    }

    printf("%f\n", ans);
    return 0;
}

