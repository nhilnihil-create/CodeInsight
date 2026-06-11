#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <functional>
#define rep(i,j,n) for(i=j;i<(n);i++)
#define rrep(i,j,n) for(i=j;i>(n);i--)
typedef long long int lli;
#define N 1000000007

using namespace std;

struct data{
    int num;
    int pos;
};

int main(){
    lli n,sum=0,a,ans;
    data data;
    lli i,j,k;
    vector<lli> point;
    point.push_back(0);
    cin>>n;
    rep(i,1,n+1){
        cin>>a;
        point.push_back(a);
        sum+=abs(point[i-1]-a);
    }
    sum+=abs(point[n]);
    point.push_back(0);
    rep(i,1,n+1){
        ans=sum-(abs(point[i]-point[i-1])+abs(point[i]-point[i+1]));
        ans+=abs(point[i-1]-point[i+1]);
        cout<<ans<<endl;
    }
}
