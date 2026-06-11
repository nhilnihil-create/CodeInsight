#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
#include <algorithm>
using namespace std;
int main(void){
    int n; cin >> n;
    vector<string> words(n);
    vector<string> pwords(n);
    string ans = "Yes";
    int i = 0;
    while (i < n) {
        cin >> words[i];
        i++;
    }
    i = 1;
    pwords[0] = words[0];
    while (i < n) {
        if (words[i].at(0) != words[i-1].at(words[i-1].length() - 1) || find(pwords.begin(), pwords.end(), words[i]) != pwords.end()) ans = "No";
        pwords[i] = words[i];
        i++;
    }
    cout << ans << endl;
}