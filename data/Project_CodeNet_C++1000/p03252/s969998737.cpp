#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;

    map<char, long long> map_s;
    map<char, long long> map_t;

    bool ok = true;
    for(long long i = 0; i < s.size(); i++){
        if(map_s.find(s[i]) != map_s.end()){
            if(map_s[s[i]] != t[i]){
                ok = false;
            }
        }
        if(map_t.find(t[i]) != map_t.end()){
            if(map_t[t[i]] != s[i]){
                ok = false;
            }
        }

        map_s[s[i]] = t[i];
        map_t[t[i]] = s[i];
    }

    if(ok == true){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    return 0;
}