#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n;cin>>n;
    vector<int> b(n);
    rep(i,n) cin>>b[i];
    stack<int> c;
    rep(k,n){
        for(int i=b.size()-1;i>=0;i--){
            if(b[i]==i+1){
                c.push(b[i]);
                b.erase(b.begin()+i);
                break;
            }
        }
    }
    if(c.size()!=n){
        cout<<-1<<endl;
        return 0;
    }
    while(c.size()){
        cout<<c.top()<<endl;
        c.pop();
    }
}