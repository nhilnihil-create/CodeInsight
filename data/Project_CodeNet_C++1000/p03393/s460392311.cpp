#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

set<char> D;

void check(string s){
    for(int j = 0; j < s.size(); j++){
        D.insert(s[j]);
    }
}


int main(){
    string s;
   
    cin >> s;

    if(s.size() == 26){
         string s2 = s;
         string s3 = s;
         sort(s2.begin(),s2.end());
         next_permutation(s.begin(), s.end());

        if(s2 == s){
            printf("-1\n");
        }
        else{
           string ans = "";
           for(int i = 0; i < s.size(); i++){
               ans.push_back(s[i]);
               if(s[i] != s3[i]){
                   break;
               }
           }
           cout << ans << endl;
        }
    }
    else{
        check(s);
        for(char i = 'a'; i <= 'z'; i++){
            if(D.find(i) == D.end()){
                s.push_back(i);
                break;
            }
        }

        cout << s << endl;
    }



    return 0;
}