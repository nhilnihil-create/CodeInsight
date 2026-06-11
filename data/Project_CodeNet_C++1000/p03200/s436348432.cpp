#include <iostream>
#include <string>
using namespace std;

string s;
long long int ans = 0; 
long long int side_white = 1;

int main(){
    cin >> s;

    if(s.length() == 1){
        ans = 0;
    }else{
        for(int i = 0;i < s.length();i++){
            if(s[i] == 'W'){
                ans += (i+1) - side_white;
                side_white++;
            }
        }
    }

    cout << ans << endl;
}