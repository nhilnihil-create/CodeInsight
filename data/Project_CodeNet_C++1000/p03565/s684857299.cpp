#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool possible(string a, string b){
    for(int i=0; i<a.size(); i++){
        if(a.at(i) == '?') continue;
        else{
            if(a.at(i) != b.at(i)) return false;
        }
    }
    return true;
}

int main(){
    string s;
    string t;
    cin >> s >> t;
    for(int i=s.size()-t.size();i>=0;i--){
        string a;
        a = s.substr(i, t.size());
        if(possible(a,t)){
            for(int k=0; k<s.size(); k++){
                if(k>=i && k<i+t.size()){
                    cout << t.at(k-i);
                }
                else{
                    if(s.at(k)=='?') cout << 'a';
                    else cout << s.at(k);
                }
            }
            cout << endl;
            return 0;
        }
    }
    cout << "UNRESTORABLE" << endl;
}