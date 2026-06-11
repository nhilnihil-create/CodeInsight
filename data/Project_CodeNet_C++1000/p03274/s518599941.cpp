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
    lli n,k,x,sum=0,Min=N,cost;
    vector<lli> vec;
    lli i,j;
    cin>>n>>k;
    rep(i,0,n){
        cin>>x;
        Min=min(Min,abs(x));
        vec.push_back(x);
    }
    if(k==1){
        cout<<Min<<endl;
    }
    else{
        Min=N;
        rep(i,0,n-k+1){
//            cout<<i+1<<"番目から"<<i+k<<"番目の蝋燭をつけるときのコストは"<<endl;
            if(vec[i]*vec[i+k-1]>=0){
                cost=max(abs(vec[i]),abs(vec[i+k-1]));
//                cout<<cost<<endl;
                Min=min(Min,cost);
            }
            else{
                cost=abs(vec[i]-vec[i+k-1])+min(abs(vec[i]),abs(vec[i+k-1]));
//                cout<<cost<<endl;
                Min=min(Min,cost);
            }
        }
        cout<<Min<<endl;
    }
}
