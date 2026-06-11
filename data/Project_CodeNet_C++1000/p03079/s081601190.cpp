#include <bits/stdc++.h>
#include <cstdio>
#include <chrono>
#include <random>
using namespace std;

#define DRACARYS ios_base::sync_with_stdio(false);cin.tie(NULL);cin.exceptions(cin.failbit);mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define PI 3.14159265
const long long int MAXN = 2e5+10;
const long long int MINN = 1e5+10;
const long long int inf = 1e18+7;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi; 
typedef stack<int> st;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    DRACARYS
    int a,b,c;
    cin>>a>>b>>c;
    if(a==b && b==c) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}