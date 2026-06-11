#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    if(s[0] == '0' || s[n - 1] == '1'){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < n - 1; i++){
        if(s[i] != s[n - 2 - i]){
            cout << -1 << endl;
            return 0;
        }
    }
    int k = 1;
    int l = n;
    for(int i = 0; i < n - 1; i++){
        if(s[i] == '1'){
            cout << k << " " << k + 1 << endl;
            k++;
        }
        else{
            cout << k << " " << l << endl;
            l--;
        }
    }
}
