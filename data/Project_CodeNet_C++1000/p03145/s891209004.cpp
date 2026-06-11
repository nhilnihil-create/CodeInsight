#include "bits/stdc++.h"
#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl
using namespace std;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define MOD 1000000007
#define mod 1000000009
#define pi 3.14159265358979323846
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
#define pb push_back
template<class T> void print(const T& x){cout << x << endl;}
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
typedef long long ll;
const int inf = 1000000001;
const ll INF = 1e18 * 4;

int main(){
    int a, b, c; cin >> a >> b >> c;
    int l1, l2;
    if(a*a + b*b == c*c){
        l1 = a; l2 = b;
    }
    if(b*b + c*c == a*a){
        l1 = b; l2 = c;
    }
    if(a*a + c*c == b*b){
        l1 = a; l2 = c;
    }
    cout << l1 * l2 / 2 << endl;
    return 0;
}


