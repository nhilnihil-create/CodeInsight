#include<bits/stdc++.h>
using namespace std;

string s, t;

int main(void){
    cin >> s >> t;
    if(s.size() < t.size()){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    vector<string> r;
    for(int i = 0; i < s.size()-t.size()+1; i++){
        string p = s.substr(i, t.size());
        for(int j = 0; j < p.size(); j++){
            if(p[j] == '?') p[j] = t[j];
        }
        if(p == t) r.push_back(s.substr(0, i)+p+s.substr(i+p.size()));
    }
    if(r.size() == 0) cout << "UNRESTORABLE" << endl;
    else{
        sort(r.begin(), r.end());
        string res = r[0];
        for(int i = 0; i < res.size(); i++){
            if(res[i] == '?') cout << 'a';
            else cout << res[i];
        }
        cout << endl;
    }
    return 0;
}
