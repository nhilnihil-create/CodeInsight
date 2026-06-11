#include <iostream>
#include <string>
using namespace std;


int check(char a){
    int ans = 0;
    if(a == 'A') ans++;
    if(a == 'C') ans++;
    if(a == 'G') ans++;
    if(a == 'T') ans++;
    return ans;
}

int main(){
    string s;
    int ans = 0, t = 0;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++){
        if(check(s.at(i)) == 1) t++;
        if(check(s.at(i)) == 0) t = 0;
        ans = max(ans, t);
    }



    cout << ans << endl;

}