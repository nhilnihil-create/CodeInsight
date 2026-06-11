#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <list>
#include <ctime>
#include <complex>
#include <bitset>
#include <tuple>

#define ff first
#define ss second

using namespace std;
using pii=pair<int,int>;
using ll=long long;

int n;
vector<vector<vector<double>>> dp;

double f(int c1, int c2, int c3, int sum)
{
    double &ret=dp[c1][c2][c3];
    if(ret>=0) return ret;
    ret=0;
    if(c3>0) ret+=f(c1,c2+1,c3-1,sum)*c3/(double)sum;
    if(c2>0) ret+=f(c1+1,c2-1,c3,sum)*c2/(double)sum;
    if(c1>0) ret+=f(c1-1,c2,c3,sum-1)*c1/(double)sum;
    ret+=n/(double)sum;
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);

    cin>>n;
    dp.resize(n+1,vector<vector<double>>(n+1,vector<double>(n+1,-1)));
    dp[0][0][0]=0;
    int c[3]={0};
    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        c[tmp-1]+=1;
    }
    cout.precision(9);
    cout<<fixed;
    cout<<f(c[0],c[1],c[2],n);

    return 0;
}
