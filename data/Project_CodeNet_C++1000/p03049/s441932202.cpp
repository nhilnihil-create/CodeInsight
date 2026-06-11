#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define sp <<" "<<
#define cst(x) cout<<fixed<<setprecision(x)
#define pi 3.14159265359
#define mod 1000000007
struct edge {
    int to; 
    int weight;
    edge(int t, int w) : to(t),weight(w) {}
};
using namespace std;
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using que_a = priority_queue<int, vector<int>, greater<int> >;
using que_d = priority_queue<int>;
using pint = pair<int,int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(){

    int n; cin >> n;
    int A = 0,B = 0,BA = 0;
    ll cnt = 0;

    rep(i,n){
        string s; cin >> s;
        if(s.at(0) == 'B' && s.at(s.size()-1) == 'A') BA++;
        else if(s.at(0) == 'B') B++;
        else if(s.at(s.size()-1) == 'A') A++;
        rep(i,s.size()-1){
            if(s.at(i) == 'A' && s.at(i+1) == 'B') cnt++;
        }
    }
    if(BA == 0){
        cnt += min(A,B);
    }
    else{
        cnt += BA-1;
        if(A >= 1 && B >= 1) cnt += min(A,B)+1;
        else if(A == 0 && B == 0);
        else cnt++;
    }
    cout << cnt << endl;
    return 0;
}
