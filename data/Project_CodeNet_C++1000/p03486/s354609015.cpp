#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

//ABC 082 b.cpp
int main() {
    string s,t;
    cin >>s>>t;
    vector<int> sv(s.size()),tv(t.size());
    rep(i,s.size()) sv[i] = s[i] - 'a';
    rep(i,t.size()) tv[i] = t[i] - 'a';

    sort(sv.begin(),sv.end());
    sort(tv.begin(),tv.end(),greater<int>());

    rep(i,s.size()){
        if(tv[i]<sv[i]){
            cout << "No" << endl;
            break;
        }else if(tv[i] > sv[i]){
            cout << "Yes" << endl;
            break;
        }

        if(i == s.size()-1){
            if(t.size() > s.size()){
                cout <<"Yes"<<endl;
            }else cout << "No" << endl;
        }
    }

}