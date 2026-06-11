#include <iostream>
#include <iomanip>
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

//lli gcd(lli a,lli b){
//    lli x,y;
//    x=max(a,b);
//    y=min(a,b);
//    if(x%y==0){
//        return y;
//    }
//    else{
//        return gcd(y,x%y);
//    }
//}
//
//lli lcm(lli a,lli b){
//    lli x,y;
//    x=max(a,b);
//    y=min(a,b);
//    return x*y/gcd(x,y);
//}

int main(){
    lli n,b;
    vector<lli> vec,ans;
    lli i,j;
    cin>>n;
    rep(i,0,n){
        cin>>b;
        vec.push_back(b);
    }
    rep(i,0,n){
        rrep(j,vec.size()-1,-1){
            if(vec[j]==j+1){
                ans.push_back(vec[j]);
                vec.erase(vec.begin()+j);
                break;
            }
            else{
                if(0==j){
                    break;
                }
            }
        }
    }
    if(ans.size()==n){
        rrep(i,n-1,-1){
            cout<<ans[i]<<endl;
        }
    }
    else{
        cout<<"-1"<<endl;
    }
}
