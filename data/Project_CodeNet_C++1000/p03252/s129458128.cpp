#include <bits/stdc++.h>
using namespace std;

int main(){
    string s,t;
    cin >> s >> t;
    vector<int> vs(26);
    vector<int> vt(26);
    
    for(int i=0; i<(int)s.size(); i++){
        int index_s = s.at(i) - 97;
        int index_t = t.at(i) - 97;
        vs.at(index_s) += 1;
        vt.at(index_t) += 1;
    }
    sort(vs.begin(),vs.end());
    sort(vt.begin(),vt.end());
    for(int i=0; i<26; i++){
        if(vs.at(i) != vt.at(i)){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}