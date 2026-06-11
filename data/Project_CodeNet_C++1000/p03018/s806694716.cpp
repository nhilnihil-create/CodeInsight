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
#include <cassert>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<int>VI;
typedef pair<int,int>P;
typedef pair<double,double>P_D;
#define PI 3.1415926535897932384626433832795
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define reprev(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define ALL(a)  (a).begin(),(a).end()
#define C_MAX(a, b) ((a)>(b)?(a):(b))
#define fi first
#define se second
#define MAX 100100//5
#define MAX_N 200100
#define MAX_B 1001001//6
#define MAX_S 10010010//7
#define SENTINEL 2000000000//9
#define NIL -1
#define MOD 1000000007
#define INF 1 << 29
#define INFTY 1000000000000000000LL
#define MAX_INT INT_MAX

int main(){
    string s;cin>>s;
    int n=(int)s.length();
    string t;
    for(int i=0;i<n-1;i++){
        if(s[i]=='B'&&s[i+1]=='C'){
            t+='D';
            i++;
        }
        else t+=s[i];
    }
    ll a=0,b=0;
    for(int i=0;i<t.length();i++){
        if(t[i]=='A')a++;
        else if(t[i]=='D')b+=a;
        else a=0;
    }
    cout<<b<<endl;
}
