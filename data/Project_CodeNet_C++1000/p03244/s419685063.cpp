#include <iostream>
#include<string>
#include<cstring>
#include <cstdio>
#include<utility>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<bitset>
#include<queue>
#include<stack>
#include<set>
#include <limits>
#include <climits>
#include <numeric>
#include<cassert>
#include<cctype>
#include<iterator>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef vector<ll>VI;
typedef vector<bool>VB;
typedef pair<ll,ll>P;
typedef pair<double,double>P_D;
#define VV(T) vector<vector<T>>
#define PI 3.1415926535897932384626433832795
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define reprev(i, n) for (ll i = (ll)n - 1; i >= 0; i--)
#define bitrep(bit,A) for(int bit=A; ;bit=(bit-1)&A)
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) (ll)((a).size())
#define c_max(a, b) (((ll)a)>((ll)b)?(a):(b))
#define c_min(a,b) (((ll)a)<((ll)b)?(a):(b))
#define chmax(x,a) x=c_max(x,a)
#define chmin(x,a) x=c_min(x,a)
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define SORT(c) stable_sort(ALL(c))
#define $(x) {cout<<#x<<" = " <<(x)<<endl;}
#define fi first
#define se second
#define MAX 100100//5
#define MAX2 200100
#define MAX_6 1001001//6
#define MAX_7 10010010//7
#define SENTINEL 2000000000//9
#define NIL -1
#define MOD 1000000007
#define INF 1<<30
#define INFTY 1000000000000000001LL
#define MAX_INT INT_MAX
#define Endl '\n'
#define greater greater<int>()
int main(){
    int n;cin>>n;
    VI even,odd;
    unordered_map<int,int>me,mo;
    rep(i,n){
        ll a;cin>>a;
        if(i%2==0){
            even.push_back(a);
            me[a]++;
            }
        else{ 
            odd.push_back(a);
            mo[a]++;
        }
    }
    P e_fi=P(0,0),e_se=P(0,0),o_fi=P(0,0),o_se=P(0,0);
    
    for(auto v:me){
        if(e_fi.se<=v.se){
            e_se=e_fi;
            e_fi=P(v.fi,v.se);
        }
        else if(e_se.se<v.se){
            e_se=v;
        }
    }
    for(auto v:mo){
        if(o_fi.se<=v.se){
            o_se=o_fi;
            o_fi=P(v.fi,v.se);
        }
        else if(o_se.se<v.se)o_se=v;
    }
    if(e_fi.fi!=o_fi.fi){
        cout<<n-e_fi.se-o_fi.se<<endl;return 0;
    }
    else{
        int one=n-e_fi.se-o_se.se,two=n-e_se.se-o_fi.se;
        cout<<min(one,two)<<endl;return 0;
    }
}
