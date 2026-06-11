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
    lli a,b,cnt=0;
    string s;
    lli i,j;
    cin>>s;
    a=0;
    b=s.size()-1;
    while(a<b){
        if(s[a]!=s[b]){
            if(s[a]=='x'){
                a++;
                cnt++;
            }
            else if(s[b]=='x'){
                b--;
                cnt++;
            }
            else{
                cnt=-1;
                break;
            }
        }
        else{
            a++;
            b--;
        }
    }
    cout<<cnt<<endl;
}
