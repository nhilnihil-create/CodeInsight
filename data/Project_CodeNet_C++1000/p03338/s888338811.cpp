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
int sdkys(int a,int b){
    if(b==0) return a;
    return sdkys(b,a%b);
}
int sskbs(int a,int b){
    return a*b/sdkys(a,b);
}
int sosu(int a){
    if(a==2){
        return 1;
    }
    for(int i=2;i<sqrt(a)+1;i++){
        if(a%i==0){
            return 0;
        }
    }
    return 1;
}
vector<int> v;
int n,m,cnt=0,ans=0,aa[220000],ab[220000];
pair<int,char> pp[220000];
string s,sa[220000];
char ch[110][110];
queue<int> que;
signed main(){
    cin>>n>>s;
    rep(i,n){
        aa[s[i]]++;
    }
    rep(i,n){
        ans=0;
        aa[s[i]]--;
        ab[s[i]]++;
        rep(j,200){
            if(aa[j]!=0&&ab[j]!=0){
                ans++;
            }
        }
        cnt=max(cnt,ans);
    }
    cout<<cnt<<endl;
}