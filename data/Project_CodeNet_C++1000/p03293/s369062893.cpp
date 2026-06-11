#include <iostream>
#include <string>
using namespace std;
int main(){
    string s,t;
    cin >> s >> t;
    for(int i = 0; i < s.size(); i++){
        string tmp = s;
        for(int j = 0; j < s.size(); j++){
            tmp[j] = s[(j+i)%s.size()];
        }
        if(tmp == t){
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}