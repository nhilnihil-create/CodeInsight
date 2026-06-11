#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <climits> // FOO_MAX, FOO_MIN
#include <cmath> 
#include <cstdlib> // abs(int)

#define roundup(n,d) ( ((n) + ((d)-1)) / (d) )
#define ll long long

using namespace std;

int main(void){
    string s;
    cin >> s;

    string head = s.substr(0,7); 
    string back = s.substr(s.size()-7, 7);

    string truekey = "keyence";
    int count = 0;
    bool headflag = true;
    for(int i = 0;i < 7;i++){
        if(head[i] == truekey[i] && headflag){
            count++;
        } else if(headflag){
            headflag = false;
        }

        if(back[i] == truekey[i] && !headflag){
            count++;
        }
    }

    if(count == 7){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}