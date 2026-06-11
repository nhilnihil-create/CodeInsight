#include <bits/stdc++.h>
using namespace std;

int main(){
    
    string s;
    cin >> s;
    int copm = 0;
    int ans = INT_MAX;
    for(int i=2; i<(int)s.size(); i++){
        int a = (s.at(i-2)-'0')*100 + (s.at(i-1)-'0')*10 + s.at(i)-'0';
        copm = abs(753 - a);
        if(ans > copm){
            ans = copm;
        }
    }
    cout << ans;
}