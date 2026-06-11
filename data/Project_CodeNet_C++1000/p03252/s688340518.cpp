#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
#include <algorithm>
#include <map>
using namespace std;
string zip(string s) {
   int counter = 1; 
   int i = 1;
   string S = "";
   int l = s.size();
   while (i <= l) {
       if (s[i] == s[i-1]) {
           counter += 1;
       } else {
           S += to_string(counter);
           counter = 1;
       }
       i++;
   }
   if (counter != 1) S += to_string(counter);
   return S;
}

int main(void){
    string s,t; cin >> s >> t;
    map<char, int> dictT;
    map<char, int> dictS;
    string answer = "Yes";
    int i = 0;
    while (i < s.size()) {
        if (dictS.count(s[i])) {
            dictS[s[i]] += 1;
        } else {
            dictS[s[i]] = 1;
        }
        if (dictT.count(t[i])) {
            dictT[t[i]] += 1;
        } else {
            dictT[t[i]] = 1;
        }
        i++;
    }
    bool flag = false;
    i = 0;
    while (i < s.size()) {
        if (dictS[s[i]] != dictT[t[i]]) flag = true;
        i++;
    }
    if (flag) answer = "No";
    if (zip(s) != zip(t)) answer = "No";

    cout << answer << endl;
}
