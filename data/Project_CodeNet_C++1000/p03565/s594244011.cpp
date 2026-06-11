#include<bits/stdc++.h>

using namespace std;

int main(){
    string s,t;
    cin >> s >> t;

    if(s.find('?') == string::npos){
        cout << s << endl;
        return 0;
    }

    bool isRestored = false;
    for(int i=s.size()-t.size(); i>=0; i--){
        if(s.at(i) == '?' || s.at(i) == t.at(0)){
            bool correspond = true;
            for(int j=1; j<t.size(); j++){
                if(!(s.at(i+j) == '?' || s.at(i+j) == t.at(j))){
                    correspond = false;
                    break;
                }
            }
            if(correspond){
                s.replace(i, t.size(), t);
                replace(s.begin(), s.end(), '?', 'a');
                isRestored = true;
                break;
            }
        }
    }

    if(isRestored){
        cout << s << endl;
    }else{
        cout << "UNRESTORABLE" << endl;
    }

    return 0;
}