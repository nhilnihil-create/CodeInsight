#include <iostream>
using namespace std;

int main(){
    string s;cin>>s;
    int w;cin>>w;
    string out = "";
    for (int i=0;i<s.size();i++){
        if (i % w == 0){
            out += s[i];
        }
    }
    cout << out << endl;
    return 0;
}