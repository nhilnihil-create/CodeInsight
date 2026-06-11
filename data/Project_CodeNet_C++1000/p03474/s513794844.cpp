#include <iostream>
#include <string>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    string s; cin >> s;
    int cnt = 0;
    for(int i = 0; i < a+b+1; i++) if(s[i] == '-') cnt++;
    if(cnt != 1){
        puts("No");
        return 0;
    }
    for(int i = 0; i < a+b+1; i++){
        int x = s[i] - '0';
        if(s[i] == '-'){
            if(i != a){
                puts("No");
                return 0;
            }
        }
        else{
            if(!(0 <= x && x <= 9)){
                puts("No");
                return 0;
            }
        }
    }
    puts("Yes");
    return 0;
}