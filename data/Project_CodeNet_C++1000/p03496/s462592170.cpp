#define _GLIBCXX_DEBUG//TLEの原因になるので注意！！！！！！！！！！！
#include<cmath>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> arr;
stack<int> st;
queue<int> qu;
queue<pair<int,int> > qu2;
priority_queue<int> pq;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rep2(i,n) for(int i=1; i<=(int)(n); i++)
#define mins(x,y) x=min(x,y)
#define maxs(x,y) x=max(x,y)
typedef set<int> set_t;
typedef set<string> set_g;
typedef complex<double> xy_t;
static const int NIL = -1;
static const int INF = 1000000007;
#define mp make_pair
#define sz(x) int(x.xise())
#define mod 1000000007
#define reps(i,s,n) for(int i = s; i < n; i++)
//#define int long long

//cerrはコメントアウトしなくても通る//ただしTLEを引き起こすことがある

int a[55];
vector<int> ans1,ans2;

int main(){
    int n;
    cin >> n;
    int mx=-INF,mi=INF;
    int mxnum=0,minum=0;
    rep(i,n){
        cin >> a[i];
        if(mx<a[i]){
            mx=a[i];
            mxnum=i+1;
        }
        if(mi>a[i]){
            mi=a[i];
            minum=i+1;
        }
    }
    int num=0;
    cerr<<mx+mi<<endl;
    if(mx==mi){
        cout<<0<<endl;
    }else if(mx+mi>0){
        rep(i,n){
            
            num++;
            ans1.push_back(mxnum);
            ans2.push_back(i+1);
            
        }
        rep(i,n-1){
            num++;
            ans1.push_back(i+1);
            ans2.push_back(i+2);
        }
        cout<<num<<endl;
        rep(i,ans1.size()){
            cout<<ans1[i]<<' '<<ans2[i]<<endl;
        }
    }else if(mx+mi<=0){
        rep(i,n){
            
            num++;
            ans1.push_back(minum);
            ans2.push_back(i+1);
            
        }
        rep(i,n-1){
            num++;
            ans1.push_back(n-i);
            ans2.push_back(n-i-1);
        }
        cout<<num<<endl;
        rep(i,ans1.size()){
            cout<<ans1[i]<<' '<<ans2[i]<<endl;
        }
    }
    return 0;
}