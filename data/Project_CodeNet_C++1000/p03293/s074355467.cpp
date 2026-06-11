#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
    string s, t;
    cin >> s;
    cin >> t;
    if(s==t){
        cout << "Yes\n";
    }
    else{
        int len = s.size();
        int i;
        bool ok = false;
        for(i=0; i<len; i++){
            s = s.back() + s.substr(0, len-1);
            if(s==t){
                ok = true;
                break;
            }
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}