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
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.length() -2 ;i++){
        if(abs(753 - ans)> abs(753-((s[i]-'0')*100 +(s[i+1]-'0')*10 + (s[i+2]-'0')))){
            ans = (s[i]-'0')*100 +(s[i+1]-'0')*10 + (s[i+2]-'0') ;
        }
    }
    cout << abs(753 - ans) << endl;
}
