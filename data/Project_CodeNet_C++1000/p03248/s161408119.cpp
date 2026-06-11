#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n - i - 2; i++){
        if(s[i] != s[n - i - 2]){
            cout << -1 << endl;
            return 0;
        }
    }
    if(s[0] == '0' || s[n - 1] == '1'){
        cout << -1 << endl;
        return 0;
    }
    int rootl = (n + 1) / 2 - 1, rooth = (n + 1) / 2 - 1;
    if(n % 2 == 0){
        cout << rooth + 1 << " " << rooth + 2 << endl;
        if(s[(n + 1) / 2 - 1] == '1') rooth = rooth + 1;
    }
    for(int i = (n + 1) / 2 - 2; i >= 0; i--){
        cout << i + 1 << " " << rootl + 1 << endl;
        cout << rooth + 1 << " " << n - i << endl;
        if(s[i] == '1'){
            rootl = i;
            rooth = n - i - 1;
        }
    }
}