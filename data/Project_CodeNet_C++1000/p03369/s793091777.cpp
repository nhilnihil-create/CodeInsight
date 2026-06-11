#include<iostream>
using namespace std;
int main(void){
    string s;
    int ans = 700;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] == 'o'){
            ans += 100;
        }
    }
    cout << ans;
}