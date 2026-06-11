#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string s, t;
    cin >> s;
    cin >> t;

    vector<int> backet(26, 0);
    for(int i = 0; i < s.length(); i++) backet[s[i]-'a']++;
    string s1 = "";
    for(int i = 0; i < 26; i++){
        while(backet[i]){
            s1 += (char)(i+'a');
            backet[i]--;
        }
    }

    for(int i = 0; i < t.length(); i++) backet[t[i]-'a']++;
    string t1 = "";
    for(int i = 25; i >= 0; i--){
        while(backet[i]){
            t1 += (char)(i+'a');
            backet[i]--;
        }
    }

    if(s1 < t1) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}