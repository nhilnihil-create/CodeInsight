#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    for(int i=0; i<k; i++){
        if(s[i]=='1'){
        }else{
            cout << s[i] << endl;
            return 0;
        }
    }
    cout << "1" << endl;
    return 0;
}

