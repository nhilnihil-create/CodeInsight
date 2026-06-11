//#include <tourist>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <tuple>
#include <deque>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <utility>
#include <complex>
#include <functional>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = (1 << 28);
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
//setprecision(15)有効数字15桁
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}
struct edge {
    int to, cost;
};
int a, b;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> a>>b;
    vector<string> s;
    for(int i=0;i<100;i++){
        if(i<50){
            string temp="";
            for(int j=0;j<100;j++){
                temp+='#';
            }
            s.push_back(temp);
        }
        else{
            string temp="";
            for(int j=0;j<100;j++){
                temp+='.';
            }
            s.push_back(temp);
        }
    }
    int i=0;
    int j=0;
    while(a!=1){
        s[i][j]='.';
        a--;
        j+=2;
        if(j>99){
            if(i%2==0){
                i+=2;
                j=1;
            }
            else{
                i+=2;
                j=0;
            }
        }
    }
    i=51;
    j=1;
    while(b!=1){
        s[i][j]='#';
        b--;
        j+=2;
        if(j>99){
            if(i%2==0){
                i+=2;
                j=1;
            }
            else{
                i+=2;
                j=0;
            }
        }
    }
    cout<<100<<" "<<100<<"\n";
    for(int i=0;i<100;i++){
        cout<<s[i]<<"\n";
    }
}
