#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int swap = 0;
    int count = 0;
    char last = s[0];

    for(int i = 1; i < s.size(); ++i){
        char curr = s[i];
        if(curr != last){
            last = curr;
            continue;
        }
        if(curr == '0'){
            last = '1';
        }else{
            last = '0';
        }
        swap++;
    }
    cout << swap << endl;

}