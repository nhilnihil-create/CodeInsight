#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
using P = pair <int, int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
ll MOD = 1000000007;
ll INF =1<<30;

int main(){
    int n;
    cin >>n;
    vector<pair<string,int>>x(n),y(n);
    rep(i,n) cin>>x[i].first>>x[i].second;
    y=x;
    sort(x.begin(),x.end());
    vector<int> c;
    rep(i,n){
        string s = x[i].first;
        priority_queue<int>q;
        while(i<n&&x[i].first==s){
            q.push(x[i].second);
            i++;
        }
        while(!q.empty()){
            int ans = q.top();
            q.pop();
            rep(i,n){
                if(ans==y[i].second){
                  cout << i+1<<endl;
                }
            }
        }
        i--;
    }
    
}