#include <iostream>
using namespace std;
int main(){
    string s; cin >> s;
    int ans = 1e9, ocnt = 0, ecnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(i%2 == 0){
            if(s[i] == '1') ocnt++;
            else ecnt++;
        }
        else{
            if(s[i] == '1') ecnt++;
            else ocnt++;
        }
        ans = min(ocnt,ecnt);
    }
    cout << ans << endl;
    return 0;
}