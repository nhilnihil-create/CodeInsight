#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;


int main(){
    string s,t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    bool flag;
    set<string> se;
    for(int i = n-m;i>=0;i--){
        flag = true;
        rep(j,m){
            if(s[i+j]==t[j] || s[j+i] == '?') continue;
            else {
                flag = false;
                break;
            }
        }
        if(flag) {
            string temp="";
            rep(j,i){
                if(s[j]=='?') temp.push_back('a');
                else temp.push_back(s[j]);
            }
            temp += t;
            for(int j = i+m;j<n;j++){
                if(s[j]=='?') temp.push_back('a');
                else temp.push_back(s[j]);
            }
            se.insert(temp);
        }
    }

    if(se.size()){
        cout << *se.begin() << endl;
    }else cout << "UNRESTORABLE" <<endl;
    
}