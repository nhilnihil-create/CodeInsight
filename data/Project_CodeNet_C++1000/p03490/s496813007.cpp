#include "bits/stdc++.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

#define FOR(i,init,a) for(int i=init; i<a; i++)
#define rep(i,a) FOR(i,0,a)
#define rrep(i,a) for(int i=a; i>=0; i--)
#define rep1(i,a) for(int i=1; i<=a; i++)
#define cout1(a) cout << a << endl;
#define cout2(a,b) cout << a << " " << b << endl;
#define cout3(a,b,c) cout << a << " " << b << " " << c << endl;
#define cout4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define mem(a,n) memset( a, n, sizeof(a))
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<VV> VVV;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LLINF = 1e18;
static const double pi = 3.141592653589793;

string s;
int gx,gy;
vector<int> nums, A, B;

bool dp(int s,int t,vector<int> &n){
    set<int> now;
    now.insert(s);
    for(auto& x:n){
        set<int> nxt;
        for(auto itr:now){
            nxt.insert(itr+x);
            nxt.insert(itr-x);
        }
        swap(now,nxt);
    }
    return (now.find(t)!=now.end());
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>s>>gx>>gy;
    s+='T';
    int cnt=0;
    rep(i,s.size()){
        if(s[i]=='T'){
            nums.push_back(cnt);
            cnt=0;
        }else{
            cnt++;
        }
    }
    
    rep(i,nums.size()){
        if(i%2==0){
            A.push_back(nums[i]);
        }else{
            B.push_back(nums[i]);
        }
    }
    
    int s=A[0];
    A.erase(A.begin());
    if(dp(s,gx,A)&&dp(0,gy,B)){
        cout1("Yes");
    }else{
        cout1("No");
    }
}