#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define bg(a) a.begin()
#define en(a) a.end()
#define all(a) bg(a), en(a)
using namespace std;
using vi = vector<int>;
using vv = vector<vi>;

int main(void){
    string s,t;cin>>s>>t;
    int n = (int)s.size();
    
    rep(i,n){
        if(s==t){
            cout << "Yes" << endl;
            return 0;
        }
        string u = s.substr(n-1,1);
        s.pop_back();
        s = u + s;
    }
    
    cout << "No" << endl;
    
    return 0;
}