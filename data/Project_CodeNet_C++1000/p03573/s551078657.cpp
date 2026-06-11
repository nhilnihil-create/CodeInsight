#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define per(i,n) for (int i = (n)-1; i >=0; --i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    map<int,int> m;
    int a;
    rep(i,3){
        cin>>a;
        m[a]++;
    }
    
    for(auto p: m){
        if(p.second%2==1){
            cout << p.first << endl;
        }
    }
    
    return 0;
}
