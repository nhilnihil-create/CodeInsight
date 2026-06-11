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

struct like2017{
    lli i,j;
    lli cnt=0;
    vector<lli> vec;
    
    like2017(lli n){
        rep(i,0,n+1){
            if(i%2==0){
                vec.push_back(0);
            }
            else{
                vec.push_back(1);
            }
        }
    }
    
    void check(lli n){
        vec[1]=0;
        vec[2]=1;
        rep(i,1,100001){
            if(vec[i]>=1){
                rep(j,2,(100000/i)+1){
                    vec[i*j]=0;
                }
                if(vec[(i+1)/2]>=1){
                    vec[i]=2;
                }
            }
        }
        rep(i,1,100001){
            if(vec[i]==2){
                cnt++;
            }
            vec[i]=cnt;
        }
    }
    
    lli search(lli a,lli b){
        lli c=vec[b]-vec[a-1];
        return c;
    }
    
    void print(){
        rep(i,1,100001){
            if(vec[i]!=vec[i-1]){
                cout<<i<<"は、"<<vec[i]<<"個目の2017に似てる数"<<endl;
            }
        }
    }
    
};

int main() {
    lli q,l,r;
    vector<lli> ans;
    lli i,j,k;
    cin>>q;
    like2017 num(100000);
    num.check(1);
    rep(i,0,q){
        cin>>l>>r;
        ans.push_back(num.search(l,r));
    }
//    num.print();
    rep(i,0,q){
        cout<<ans[i]<<endl;
    }
}
