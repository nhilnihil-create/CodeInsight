#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#define MAX(x,y) (x > y ? x : y)

using std::cout;
using std::cin;
using std::endl;
using std::pow;
using std::vector;
using std::string;

int main(){
    string s;
    int res=0,tmp=0;
    cin >> s;
    for(int i=0;i<s.length();i++){
        if(s[i] == 'A' || s[i] == 'C' || s[i] == 'T' || s[i] == 'G'){
            tmp++;
            res = MAX(res,tmp);
        }else{
            tmp = 0;
        }
    }
    cout << res;
}