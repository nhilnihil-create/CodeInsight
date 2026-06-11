#include <iostream>
using namespace std;

int main(){
    int n;cin>>n;
    string s;cin>>s;
    
    int r,b;
    r = b = 0;
    for (auto c:s){
        if (c == 'R'){
            r++;
        } else {
            b++;
        }
    }
    if (r > b){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}