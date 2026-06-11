#include <bits/stdc++.h>
using namespace std;
struct Fast {Fast(){std::cin.tie(0);ios::sync_with_stdio(false);cout.precision(20);}} fast;

/* define */
#define FOR(I,X,Y) for(long long (I)=(X);(I)<(Y);(I)++)
#define REP(I,X,Y) for(long long (I)=(Y)-1;(I)>=(X);(I)--)
#define ALL(X) (X).begin(),(X).end()
#define pb push_back
#define COUNT(V,X) (upper_bound((V).begin(),(V).end(),X)-lower_bound((V).begin(),(V).end(),X))
#define debug(x) cerr<<#x<<':'<<x<<endl;
#define DEBUG(v) cerr<<#v<<':';for(auto xXx:v)cerr<<xXx<<' ';cerr<<endl;
#define Yes(X) if(X){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define YES(X) if(X){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define ctoi(C) (C-'0')

/* alias */
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<long long>;
using vll = vector<vector<long long>>;
using pi = pair<int,int>;
using pl = pair<long long,long long>;
template<typename T> using PQ = priority_queue<T>;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

/* const */
const long long dx[] = {1,0,-1,0};
const long long dy[] = {0,1,0,-1};
const long long dx8[] = {1,1,0,-1,-1,-1,0,1};
const long long dy8[] = {0,1,1,1,0,-1,-1,-1};
const long long dx9[] = {1,1,0,-1,-1,-1,0,1,0};
const long long dy9[] = {0,1,1,1,0,-1,-1,-1,0};
const int INF = 1000000007;
const long long LINF = 1000000000000000007;

/* func */
template <typename T> inline bool chmin(T& a, const T& b) {if (a > b) a = b; return a > b;}
template <typename T> inline bool chmax(T& a, const T& b) {if (a < b) a = b; return a < b;}
long long max(long long x,int y){return max(x,(long long)y);}
long long max(int x,long long y){return max((long long)x,y);}
long long min(long long x,int y){return min(x,(long long)y);}
long long min(int x,long long y){return min((long long)x,y);}

/* liblary */



/* main */

ld func(ld& speed,ld t,ld max,ld lastspeed){
    ld firstspeed = speed;
    if(max <= lastspeed){
        speed = min(speed+t,max);
        if(max == speed){
            return speed*t - (max-firstspeed)*(max-firstspeed)/2;
        }
        else{
            return firstspeed*t + t*t/2;
        }
    }
    if(firstspeed+t <= lastspeed){
        speed = firstspeed+t;
        return firstspeed*t + t*t/2;
    }
    if((firstspeed+lastspeed+t)/2 <= max){
        speed = lastspeed;
        ld t_first = (lastspeed-firstspeed+t)/2;
        ld t_second = t-t_first;
        ld first = firstspeed*t_first + t_first*t_first/2;
        ld second = lastspeed*t_second + t_second*t_second/2;
        return first + second;
    }
    speed = lastspeed;
    ld t_first = max-firstspeed;
    ld t_third = max-lastspeed;
    ld t_second = t - t_first - t_third;
    ld first = firstspeed*t_first + t_first*t_first/2;
    ld second = max*t_second;
    ld third = lastspeed*t_third + t_third*t_third/2;
    return first+second+third;
}

/*
y = firstspeed + x;
y = t-x + lastspeed;
firstspeed + x = t-x + lastspeed;
x = (lastspeed-firstspeed+t)/2;
y = (firstspeed+lastspeed+t)/2;
*/

signed main(){
    ll N;
    cin >> N;
    ld t[N+2]={0},v[N+2]={0};
    FOR(i,0,N)cin >> t[i+1];
    FOR(i,0,N)cin >> v[i+1];
    REP(i,1,N+1)chmin(v[i],v[i+1]+t[i]);
    ld ans = 0;
    ld speed = 0;
    FOR(i,1,N+1){
        ans += func(speed,t[i],v[i],v[i+1]);
    }
    cout << ans << endl;
}