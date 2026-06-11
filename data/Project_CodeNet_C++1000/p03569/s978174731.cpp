#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    string s;
    cin >> s;

    long long count_x = 0;
    long long l = 0;
    long long r = s.size()-1;
    while(l < r){
        if(s[l] == s[r]){
            l++;
            r--;
        }
        else if(s[l] == 'x'){
            l++;
            count_x++;
        }
        else if(s[r] == 'x'){
            r--;
            count_x++;
        }
        else{
            count_x = -1;
            break;
        }
    }
    cout << count_x << endl;

    return 0;
}