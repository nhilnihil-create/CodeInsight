
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
using namespace std;

#define MOD 1000000007

using ll = int;

int main(void) {
    
    string s;
    cin >> s;
    int a=0,b=0,c=0;
    for(int i=0;i<s.length();++i){
        if(s[i]=='a'){
            a++;
        }else if(s[i]=='b'){
            b++;
        }else{
            c++;
        }
    }
    if(max(max(abs(a-b),abs(b-c)),abs(c-a))<=1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
