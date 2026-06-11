           //In the name of ALLAH the most merciful the most beneficial

#include<cstdio>
#include<cstring>
#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<fstream>
#define sc(x) scanf("%d",&x)
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORd(i,a,b) for(int i=a;i>b;i--)
#define ff first
#define ss second
#define sz(x) x.size()
#define pb push_back

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;
const int con = 1e9;
static const int INF = 0x3f3f3f3f;
static const int MOD = 998244353;

int main(){
    
    int n;
    int r,c;
    sc(n);sc(r);sc(c);
    int ans1 = n-r+1;
    int ans2 = n-c+1;
    cout << ans2*ans1;
    return 0;
}

