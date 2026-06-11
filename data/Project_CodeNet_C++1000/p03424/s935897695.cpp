#include <iostream>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    int i;
    for(i=0;i<n;i++){
        cin >> s;
        if(s == "Y"){
            cout << "Four" << endl;
            return 0;
        }
    }
    cout << "Three" << endl;
    return 0;
}