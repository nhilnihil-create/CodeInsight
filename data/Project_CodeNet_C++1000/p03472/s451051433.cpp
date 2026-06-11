#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <stack>
#include <functional>
#include <sstream>
#define rep(i,j,n) for(i=j;i<(n);i++)
#define rrep(i,j,n) for(i=j;i>(n);i--)
typedef long long int lli;
#define N 1000000007
#define M 998244353

using namespace std;

int main() {
    lli n,h,a,b,c=0,cnt=0;
    vector<lli> vec;
    lli i,j,k;
    cin>>n>>h;
    rep(i,0,n){
        cin>>a>>b;
        vec.push_back(b);
        c=max(c,a);
    }
    sort(vec.begin(),vec.end());
    rep(i,0,n){
        if(vec[n-1-i]>c){
            h-=vec[n-1-i];
            cnt++;
            if(h<=0){
                h=0;
                break;
            }
        }
        else{
            break;
        }
    }
    if(h%c>0){
        cnt++;
    }
    cnt+=h/c;
    cout<<cnt<<endl;
}
