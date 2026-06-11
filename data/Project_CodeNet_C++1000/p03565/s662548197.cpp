#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;

    if (t.size()>s.size()){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }

    bool can = false;
    for (int i = s.size()-1; i>=0; i--){
        if (s.at(i) == '?' || s.at(i) == t.at(t.size()-1)){
            int count = 1;
            int forS = i-1;
            if (t.size() > 1){           
                for (int j = t.size()-2; j>=0; j--){
                    if (forS >= 0){
                        if (s.at(forS) == '?' || s.at(forS) == t.at(j)){//もんだい
                            count++;
                        }else{
                            break;
                        }
                    }

                    forS--;
                }
            }
            forS = i;
            if (count == t.size()){
                for (int j = t.size()-1; j>=0; j--){
                    s.at(forS) = t.at(j);
                    forS--;
                }
                can = true;
                break;
            }
        }
    }

    if (can){
        for (int i = 0; i<s.size(); i++){
            if (s.at(i) == '?'){
                s.at(i) = 'a';
            }
        }
        cout << s << endl;
    }else{
        cout << "UNRESTORABLE" << endl;
    }

    return 0;
}