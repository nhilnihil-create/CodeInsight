#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <iostream>
#include <fstream>
#include <numeric>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>
#include <set>
#include <map>
#include <functional>
#include <bitset>
#include <iomanip>
#include <stack>
#include <list>
using namespace std;
#define ll           long long
#define all(v)       (v).begin() , (v).end()
#define vi           vector <ll>
#define vii          vector <pair<ll,ll>>
#define ii           pair<ll,ll>
#define sz(v)	     ((int)((v).size()))
#define lp(i,a,b)    for(int i=a;i<b;i++)
#define pb           push_back
#define pf           push_front
#define F            first
#define S            second
#define endl         "\n"
#define IOS          ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const double PI = 3.14159265358979323846;
const ll inf=2e9,MOD=1e9+7,MAX=1e5+2;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    IOS;
    int n;
    cin>>n;
    int a[n];
    map<int,int>cnt1,cnt2;
    lp(i,0,n){
        cin>>a[i];
        if(i%2){
            cnt1[a[i]]++;
        } else
            cnt2[a[i]]++;
    }
    vector<pair<int,int>>v,x;
    for(auto i:cnt1)
        v.pb({i.S,i.F});
    for(auto i:cnt2)
        x.pb({i.S,i.F});
    sort(v.rbegin(),v.rend());
    sort(x.rbegin(),x.rend());
    int temp=v[0].F+x[0].F;
    if(v[0].S==x[0].S){
        if(sz(v)==1&&sz(x)==1)
            temp-=x[0].F;
        else if(sz(v)==1)
            temp+=-x[0].F+x[1].F;
        else if(sz(x)==1)
            temp+=-v[0].F+v[1].F;
        else
            temp-=v[0].F,temp+=max(x[1].F,v[1].F);
    }
    cout<<n-temp;
}
