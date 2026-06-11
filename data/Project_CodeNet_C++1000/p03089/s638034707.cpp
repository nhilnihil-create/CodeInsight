//  Created by conan1024hao in 2020.
//  Copyright © 2020 conan1024hao. All rights reserved.
//  専用ライブラリです、自由にコピーして構いません。
//  感谢看我的代码！Wechat:conan1024hao Twitter/QQ:810396815
#pragma GCC optimize ("O3")
#include <iostream>
#include <iomanip>
#include <istream>
#include <ostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <utility>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <cctype>
#include <cstdlib>
#define IINF 10e8
#define INF 10e17
#define MOD 1000000007
#define mod 1000000007
#define rep(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define Endl endl
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define mmax(x,y)(x>y?x:y)
#define mmin(x,y)(x<y?x:y)
#define chmax(x,y) x=mmax(x,y)
#define chmin(x,y) x=mmin(x,y)
#define all(x) (x).begin(),(x).end()
#define siz(x) (ll)(x).size()
#define PI acos(-1.0)
using namespace std;
//using Int=int_fast64_t;
typedef long long int ll;
typedef long long int LL;
typedef pair<ll,ll>Pll;
typedef pair<int,int>Pin;
template<class T> using V=vector<T>;
long long GCD(long long a, long long b) { return b ? GCD(b, a%b) : a; }
long long LCM(long long a, long long b)  {return a/GCD(a,b)*b;}
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
char dir[4]={'u','l','d','r'};
ll cmp1(pair<ll,string>a,pair<ll,string> b){
        if(a.fi!=b.fi)
        return a.fi<b.fi;
        else
        return a.se<b.se;
}

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
int main(){//問題をちゃんと見ろ!!!!!!!!!!!!!!!!!      llか??????????统一类型        memset()!!!!!!!!!!!!       ペナを減らせ!!!!!!!!!!!!!
    cin.tie(0);
    ios::sync_with_stdio(false);
    //-------------------------------
    int n;cin>>n;
    V<int>b(n);
    for(int i=0;i<n;i++)cin>>b[i];
    if(n==1&&b[0]==1){
        cout<<1<<endl;
        return 0;
    }

    vector<int>ans;
    bool color[101];
    memset(color,0,sizeof(color));
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=0;j--){
            if(color[j]==1)continue;
            int cnt=0;
            for(int z=0;z<j;z++){
                if(color[z]==1)cnt++;
            }
            if(b[j]==j+1-cnt){
                //cout<<b[j]<<endl;
                ans.pb(b[j]);
                color[j]=1;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(color[i]==0)
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    reverse(all(ans));
    if(ans.size()<n){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<endl;
    }
    //-------------------------------
    return 0;
}
//---------------------------------------------------------------------------






