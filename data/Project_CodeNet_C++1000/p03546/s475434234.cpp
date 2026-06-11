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

int n,m,c[10][10];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    IOS;
    cin>>n>>m;
    lp(i,0,10)
        lp(j,0,10)
            cin>>c[i][j];
    lp(k,0,10)
        lp(i,0,10)
            lp(j,0,10)
                if(c[i][j]>c[i][k]+c[k][j])
                    c[i][j]=c[i][k]+c[k][j];
    ll res=0;
    lp(i,0,n){
        lp(j,0,m){
            int x;
            cin>>x;
            if(x!=-1)
                res+=c[x][1];
        }
    }
    cout<<res;
}
