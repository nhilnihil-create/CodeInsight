#include<stdio.h>
#include<iostream>
#include<vector>
#include <fstream>
#include<math.h>
#include <numeric>
#include<algorithm>
#include <stdlib.h>
# include <map>

using namespace std;

int main(){
    int n;
    string s;
    bool flag = true;
    cin >> n;
    while(flag){
        s = to_string(n);
        if ((s[0] == s[1]&&(s[1] == s[2]))){
            flag = false;
        }
        else{
            n += 1;
        }
    }
    cout << n << endl;
}
