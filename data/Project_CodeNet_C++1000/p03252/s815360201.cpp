#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;
int main(){
    string s,t;
    map<char,char> mp;
    set<char> sti, sto;
    cin >> s >> t;
    int n = s.size();
    for(int i = 0; i < n; ++i){
        char c = s[i];
        if(sti.count(c) == 1){
            if(mp[c] != t[i]){
                puts("No");
                return 0;
            }
        }
        else{
            sti.insert(c);
            if(sto.count(t[i]) == 1){
                puts("No");
                return 0;
            }
            mp[c] = t[i];
            sto.insert(t[i]);
        }
    }
    puts("Yes");
    return 0;
}