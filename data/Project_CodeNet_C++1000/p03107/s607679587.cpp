#include <bits/stdc++.h>
#include<algorithm>//next_permutation
using namespace std;
 
#define rep(i,n) for(int i=0;i<(n);i++)
#define repa(i,a,n) for(int i=(a);i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define rrepa(i,a,n) for(int i=n-1;i>=(a);i--)
#define all(a) (a).begin(),(a).end()
#define MOD 1000000007
#define cmax(a,b) a=max(a,b)
#define cmin(a,b) a=min(a,b)
#define vc vector
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
 
 
int main (){
    string s;
    cin >> s;
    int n = s.size();
    int z =0,o;
    rep(i,n){
        if(s[i]=='0')z++;
    }
    o = n-z;
    cout << min(o,z)*2 <<endl;
}