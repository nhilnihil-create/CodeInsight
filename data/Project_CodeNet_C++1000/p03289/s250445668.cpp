#include <iostream>
using namespace std;

int main(void){
    string s;
    int c = 0;
    cin >> s;
    bool flag = true;
    for (int i=0; i<s.size(); i++){
        if (i==0 && s[i]!='A'){
            flag = false;
            break;
        } else if(i>=2 && i<=s.size()-2){
            if (s[i] == 'C') c++;
            else if (s[i]>='A' && s[i]<='Z'){
                flag = false;
                break;
            }
        }
    }
    if ((s[1]>='A' && s[1]<='Z') || (s[s.size()-1]>='A' && s[s.size()-1]<='Z')) flag = false;
    if (c != 1) flag = false;
    cout << (flag ? "AC" : "WA") << endl;
    return 0;
}