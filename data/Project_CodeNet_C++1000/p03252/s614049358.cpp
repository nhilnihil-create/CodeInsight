#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string S,T;
    cin >> S >> T;
    map<char, char> m;
    bool possible=true;
    for(int i=0; i<S.size(); i++){
        char s=S.at(i);
        char t=T.at(i);
        if(m.count(s)){
            if(m[s] != t) possible=false;
        }
        m[s] = t;
    }
    set<char> change;
    for(auto p: m){
        char c=p.second;
        if(change.count(c)) possible=false;
        change.insert(c);
    }
    if(possible){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}