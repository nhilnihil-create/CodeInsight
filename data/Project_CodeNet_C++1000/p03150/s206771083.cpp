#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> pll;
const int INF=1e9;
const ll MOD=1e9+7;

ll gcd(ll x,ll y){
    if(y==0) return 0;
    return gcd(y,x%y);
}

int dis2(int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main(){
    string s;cin>>s;
    string t="keyence";
    int f=0,b=0;
    while(f<7&&s[f]==t[f]) f++;
    while(b<7&&s[(int)s.size()-1-b]==t[6-b]) b++;
    if(f==7||b==7||f+b>=7){
        cout<<"YES"<<endl;
    }else cout<<"NO"<<endl;
    return 0;
}