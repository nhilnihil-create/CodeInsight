#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define sp <<" "<<
#define cst(x) cout<<fixed<<setprecision(x)
#define pi 3.14159265359
#define mod 1000000007
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;
using Graphi = vector<vi>;
using que_a = priority_queue<int, vector<int>, greater<int> >;
using que_d = priority_queue<int>;
using pint = pair<int,int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
struct edge {
    int to; 
    int weight;
    edge(int t, int w) : to(t),weight(w) {}
};

int main(){

    int n; cin >> n;
    vector<int> x(n),y(n),h(n);
    rep(i,n) cin >> x.at(i) >> y.at(i) >> h.at(i);

    ll height_temp;
    int k = 0;
    while(h.at(k) == 0) k++;
    int x_ans,y_ans;
    bool ok;
    rep(X,101){
        rep(Y,101){
            ok = true;
            height_temp = h.at(k) + abs(X-x.at(k)) +abs(Y-y.at(k));
            rep(i,n){
                if(max(height_temp - abs(X-x.at(i)) - abs(Y-y.at(i)),0LL) != h.at(i)) ok = false; 
            }
            if(ok){
                x_ans = X;
                y_ans = Y;
                break;
            }
        }
        if(ok) break;
    }
    cout << x_ans sp y_ans sp height_temp << endl;

    return 0;

}