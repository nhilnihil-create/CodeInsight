#include <iostream>        
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, counter = 0;
    string s;
    cin >> n;
    cin >> s;
    for(int i = 1; i < n; ++i){
        if(s[i]=='E'){
            ++counter;
        }
    }
    int ans = counter;
    for(int i = 1; i < n; ++i){
        if(s[i-1]=='W' && s[i]=='W'){
            ++counter;
        }else if(s[i-1]=='E' && s[i]=='E'){
            --counter;
        }if(counter < ans){
            ans = counter;
        }
    }

cout << ans << "\n";
return 0;
}
