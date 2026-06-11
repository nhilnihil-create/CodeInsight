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

int main(){
    string s,ans;
    lli i,j,k;
    char t;
    map<char,lli> map;
    cin>>s;
    rep(i,0,s.size()){
        map[s[i]]++;
    }
    if(s.size()!=26){
        rep(i,0,26){
            t='a'+i;
            if(map[t]==0){
                ans=s+t;
                cout<<ans<<endl;
                exit(0);
            }
        }
    }
    else{
        if(s=="zyxwvutsrqponmlkjihgfedcba"){
            cout<<"-1"<<endl;
            exit(0);
        }
        else{
            rep(i,0,26){
                j=25-i;
                string y;
                y=s.substr(j,i+1);
                rep(k,1,26){
                    if(y.find(y[0]+k)!=string::npos){
                        y=y[0]+k;
//                        cout<<y<<endl;
                        ans=s.substr(0,j)+y;
                        cout<<ans<<endl;
                        exit(0);
                    }
                }
            }
        }
    }
}
