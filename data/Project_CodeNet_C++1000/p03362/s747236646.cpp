#pragma GCC optimize ("O3")
#include <iostream>
#include <iomanip>
#include <istream>
#include <ostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <utility>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <cctype>
#include <cstdlib>
#define IINF 100000000
#define INF 300000000000000000
#define MOD 1000000007
#define mod 1000000007
#define INT_MAX_ 2147483647
#define REP(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define REPE(i, a, n) for (ll i = a; i <= (ll)(n); i++)
#define rep(i,n)for (ll i = 0; i < (ll)(n); i++)
#define Endl endl
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define mmax(x,y)(x>y?x:y)
#define mmin(x,y)(x<y?x:y)
#define chmax(x,y) x=mmax(x,y)
#define chmin(x,y) x=mmin(x,y)
#define all(x) (x).begin(),(x).end()
#define siz(x) (ll)(x).size()
#define PI acos(-1.0)
#define me memset
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int,int>Pin;
typedef pair<ll,ll>Pll;
template<class T> using V=vector<T>;
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
long long GCD(long long a, long long b) {return b?GCD(b,a%b):a;}
long long LCM(long long a, long long b) {return a/GCD(a,b)*b;}
int dx[5]={-1,0,1,0,0};
int dy[5]={0,-1,0,1,0};
int ddx[8]={-1,0,1,0,1,1,-1,-1};
int ddy[8]={0,-1,0,1,1,-1,1,-1};
ll cmp1(pair<ll,ll>a,pair<ll,ll> b){
        if(a.se!=b.se)
        return a.se<b.se;
        else
        return a.fi<b.fi;
}
//----------------------------------------------------------------------
#define N 100000
vector<ll>prime(N);
void makeprime() {
        int j, n = 29, i = 9, sqrtn;//从第10个质数开始计算，第10个质数是29
        prime[0] = 2;
        prime[1] = 3;
        prime[2] = 5;
        prime[3] = 7;
        prime[4] = 11;
        prime[5] = 13;
        prime[6] = 17;
        prime[7] = 19;
        prime[8] = 23; //之前已有9个质数在表中
        while (i < N) {
            j = 0; //每次从表头开始试除
            sqrtn = sqrt(n); //n的平方根
            while (prime[j] <= sqrtn) {
                if (n % prime[j] == 0) break; //若n能整除质数表中的某数，则跳出
                j++;
            }
            if (prime[j] > sqrtn) {
                prime[i] = n;
                i++;
            }
            n += 2; //除了2，偶数不会是质数，因此跳过所有偶数
        }
}
//----------------------------------------------------------------------
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    //-------------------------------  
    //ll begin_time=clock();
    //-------------------------------
    int n;cin>>n;
    makeprime();
    V<ll>ans;
    for(ll i=0;i<10000;i++){
        if(prime[i]>55555)break;
        if(prime[i]%5==1){
            ans.pb(prime[i]);
        }
        if(ans.size()==n)break;
    }
    for(ll i=0;i<n;i++)cout<<ans[i]<<" ";cout<<endl;
    //-------------------------------  
    //ll end_time=clock();cout<<"time="<<end_time-begin_time<<"ms"<<endl;
    //-------------------------------
    return 0;
}
//----------------------------------------------------------------------



































