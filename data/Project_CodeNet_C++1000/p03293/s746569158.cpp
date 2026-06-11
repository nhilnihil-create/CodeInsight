#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <cassert>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define srep(i,n,m) for(int i=n;i<m;i++)
#define elif else if
#define INF 1000000007
#define pi 3.141592653589793
using namespace std;
int saidaikouyakusuu(int a,int b){
    if(b==0) return a;
    return saidaikouyakusuu(b,a%b);
}
int saisyoukoubaisuu(int a,int b){
    return a*b/saidaikouyakusuu(a,b);
}
int n,m,cnt=0,aa[220000],ans=0,x,y,ab[220000];
pair<int,int> pp[220000];
string s,ss[220000];
char c;
queue<char> que;
signed main(){
    cin>>s>>ss[0];
    rep(i,s.size()){
        que.push(s[i]);
    }
    rep(i,s.size()){
        cnt=0;
        rep(j,s.size()){
            if(que.front()!=ss[0][j]){
                cnt++;
            }
            que.push(que.front());
            que.pop();
        }
        if(cnt==0){
            cout<<"Yes"<<endl;
            return 0;
        }
        que.push(que.front());
        que.pop();
    }
    cout<<"No"<<endl;
}