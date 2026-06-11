#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    int taila = 0;
    int frontb = 0;
    int banda = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i][0] == 'B' && s[i][s[i].length()-1] == 'A') banda++;
        else if(s[i][0] == 'B') frontb++;
        else if(s[i][s[i].length()-1] == 'A') taila++;
        
        for(int j = 1; j < s[i].length(); j++){
            if(s[i][j-1] == 'A' && s[i][j] == 'B') ans++;
        }
    }
    
    if(banda > 0){
        ans += banda-1;
        if(taila > 0){
            taila--;
            ans++;
        }
        if(frontb > 0){
            frontb--;
            ans++;
        }
    }

    if(taila > frontb) ans += frontb;
    else ans += taila;
    
    cout << ans << endl;
    return 0;
}