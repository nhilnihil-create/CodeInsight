#include <iostream>
#include <cstring>
#include <cstdio>
#include<utility>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<bitset>
#include<queue>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
typedef pair<double,double>P_D;
#define PI 3.1415926535897932384626433832795
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define reprev(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define ALL(a)  (a).begin(),(a).end()
#define MAX 100100
#define MAX_N 200100
#define SENTINEL 2000000000
#define MAX_B 1001001
#define NIL -1
#define MOD 1000000007
#define INF 1 << 29
#define INFTY 1000000000000000000LL

int main(){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int m=min(x,y);
    int ma=max(x,y);
    int z=(x>y)?(x-y)*a:(y-x)*b;
    int s_1=m*2*c+z;
    int s_2=x*a+y*b;
    int s_3=ma*2*c;
    cout<<min(s_1,min(s_2,s_3))<<endl;
}