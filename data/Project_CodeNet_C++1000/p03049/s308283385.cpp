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

int main(){
    lli n,t=0,a=0,b=0,c=0;
    string s;
    lli i,j;
    cin>>n;
    rep(i,0,n){
        cin>>s;
        rep(j,0,s.size()-2){
            if((s[j]=='A')&&(s[j+1]=='B')){
                t++;
            }
        }
        if(s[0]=='B'){
            if(s[s.size()-1]=='A'){
                c++;
            }
            else{
                b++;
            }
        }
        else{
            if(s[s.size()-1]=='A'){
                a++;
            }
        }
    }
    if(c>0){
        if(c>1){
            t+=c-1;
        }
        if(a>0){
            a--;
            t++;
        }
        if(b>0){
            b--;
            t++;
        }
    }
    t+=min(a,b);
    cout<<t<<endl;
}
