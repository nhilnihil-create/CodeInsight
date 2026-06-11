#include<iostream>
#include<string>
using namespace std;

int main(void){
    int count = 0;
    string s, keyence = "keyence";
    cin >> s;
    int len = s.size();
    int i = 0;
    while(s[i] == keyence[i++]){
        count++;
        if(count == 7){
            cout << "YES" << endl;
            return 0;
        }
    }
    i = 0;
    while(s[len-1-i] == keyence[6-i]){
        i++;
        count++;
        if(count == 7){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}