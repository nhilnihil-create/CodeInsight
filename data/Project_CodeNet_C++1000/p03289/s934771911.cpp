#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;
    int slen = s.length();
    string result = "AC";
    if(s[0] != 'A'){
        result = "WA";
    }
    int count = 0;
    for(int i = 1; i < slen; i++){
        if(isupper(s[i])){
            if(i == 1 || i == slen - 1 || s[i] != 'C'){
                result = "WA";
            }
            count++;
        }
    }
    if(count != 1){
        result = "WA";
    }
    cout << result << endl;
    return 0;
}