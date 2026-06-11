#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
    string s,t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end(),greater<int>());
    
    if(s < t) cout << "Yes" << endl;
    else cout << "No" << endl;
}