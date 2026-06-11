#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    string s,t;
    cin >> s >> t;
    
    vector<int> start(26,-1),goal(26,-1);
    rep(i,s.size()){
        int a = s[i] - 'a';
        int b = t[i] - 'a';
        if(start[a] != -1 || goal[b] != -1){
            if(start[a] != b || goal[b] != a){
                cout << "No" << endl;
                return 0;
            }
        }else{

            start[a] = b;
            goal[b] = a;
        }
    }

    cout << "Yes" << endl;

    return 0;
}
