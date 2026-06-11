#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    long long int k;
    cin >> k;
    int ans;
    for(int i = 0; i < s.length(); i++){
        if(s[i] != '1'){
            ans = s[i]-'0';
            break;
        }else if(i == k-1){
            ans = 1;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
