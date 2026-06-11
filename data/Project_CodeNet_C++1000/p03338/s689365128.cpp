#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main(){
    
    string s;
    int n;
    cin >>n;
    cin >> s;
    vector<int> v(s.size());
    rep(i,s.size()){
        v[i] = s[i]-'a';
    }
    int ans = 0;
    for(int i=1;i<=s.size()-1;i++){
        vector<int> a,b;
        a = vector<int>(v.begin(),v.begin()+i+1);
        b = vector<int>(v.begin()+i+1,v.end());
        set<int> sa,sb;
        for(auto v:a) sa.insert(v);
        for(auto v:b) sb.insert(v);

        vector<int> p;
        for(auto v:sa) p.push_back(v);
        for(auto v:sb) p.push_back(v);
        sort(p.begin(),p.end());
        int temp = 0;
        for(int i=0;i<p.size()-1;i++){
            if(p[i]==p[i+1]) temp++;
        }
        ans = max(ans,temp);
    }

    cout << ans << endl;


}