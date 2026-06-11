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
using Graph = vector<vector<int>>;
using que_a = priority_queue<int, vector<int>, greater<int> >;
using que_d = priority_queue<int>;
using pint = pair<int,int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


int main(){

    int n; cin >> n;
    vector<int> c(n-1),s(n-1),f(n-1);
    rep(i,n-1) cin >> c.at(i) >> s.at(i) >> f.at(i);

    for(int point = 0; point <= n-2; point++){
        ll time = 0;
        for(int i = point; i <= n-2; i++){
            if(time <= s.at(i)) time = s.at(i);
            else{
                time = ((time -1)/f.at(i)+1)*f.at(i);
            }
            time += c.at(i);
        }
        cout << time << endl;
    }
    cout << 0 << endl;
    return 0;   

}
