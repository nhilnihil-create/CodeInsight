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

struct train{
    
    vector<lli> start,frame,cost;
    
    train(lli n){
        lli c,s,f,i;
        rep(i,0,n-1){
            cin>>c>>s>>f;
            cost.push_back(c);
            start.push_back(s);
            frame.push_back(f);
        }
    }
    
    lli search(lli a,lli n){
        lli t=0,i;
        rep(i,a,n-1){
//            cout<<"今は"<<t<<"秒で、"<<i<<"駅についている"<<endl;
            if(t<=start[i]){
                t=start[i];
            }
            else{
                if((t-start[i])%frame[i]!=0){
                    lli b=(t-start[i])/frame[i];
                    b++;
                    t=start[i]+b*frame[i];
                }
            }
            t+=cost[i];
        }
        return t;
    }
    
};

int main() {
    lli n;
    lli i,j,k;
    cin>>n;
    train daiya(n);
    rep(i,0,n){
        cout<<daiya.search(i,n)<<endl;
    }
}
