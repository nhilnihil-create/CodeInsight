#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;

int h,w,n;
int x,y;
string s,t;

bool calc(char L,char R,int Max,int sta){
    int left=1,right=Max;
    if (s[n-1]==R) right-=1; 
    if (s[n-1]==L) left+=1; 
    per(i,n-1){
        if (t[i]==R) left=max(1,left-1);
        if (t[i]==L) right=min(right+1,Max); 
         
        if (s[i]==R) right-=1;
        if (s[i]==L) left+=1;
        

        if (left>right) return false;
    }

    return left<=sta && sta<=right;

}

void solve(){
    cin >> h >> w >> n;
    cin >> y >> x;
    cin >> s >> t;
    bool a1=calc('L','R',w,x);
    bool a2=calc('U','D',h,y);
    puts(a1&&a2 ? "YES" : "NO");
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}