#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    int count=0;
    bool chk=true;
    auto comp = [](char a, char b) { return a-'a' > b-'a'; };
    sort(s.begin()+2, s.end()-1, comp);
  
    if(s.front()!='A') chk=false;
    if(s[s.size()-2]!='C') chk=false;
    for(int i = 1; i < s.size()-2; i++) {
        if(!islower(s[i])) chk=false;
    }
    if(!islower(s.back())) chk=false;
    cout << (chk ? "AC" : "WA") << endl;
    return 0;
}