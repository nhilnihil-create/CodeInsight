#include <iostream>
using namespace std;

int main(){
    string s;cin>>s;
    if (s.size() == 3){
        for (int i=2;i>=0;i--){
            cout << s[i];
        }
    } else {
        cout << s;
    }
    cout << endl;
}