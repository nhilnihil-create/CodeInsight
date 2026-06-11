#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
    string s,t;
    cin >> s >> t;
    vector<char> a(26, -1);

    for(int i = 0; i < s.size(); i++){
        if(a[s[i]-'a'] == -1){
            a[s[i]-'a'] = t[i];
        }else if(a[s[i]-'a'] != t[i]){
            cout << "No" << endl;
            exit(0);
        }
    }
    for(int i = 0; i < 26-1; i++){
        if(a[i] != -1){
            for(int j = i+1; j < 26; j++){
                if(a[i] == a[j]){
                    cout << "No" << endl;
                    exit(0);
                }
            }
        }
    }
    
    cout << "Yes" << endl;

}