#include<iostream>
#include<string>
#include<stdio.h>
#include <algorithm>
#include <set>
#include<math.h>
#include<vector>
#include<map>
using namespace std;

int main(){
    int n;cin >> n;
    map<string,int>tmp;
    string s[100];
    int flag = 1;
    for(int i = 0;i < n;i++){
        cin >> s[i];
        string t = s[i];
        tmp[t]++;
        if(tmp[t] >= 2)flag = 0;
    }
    for(int i = 0;i < n;i++){
        if(flag == 0)break;
        string t = s[i];
        if(i>=1){
            string tm = s[i-1];
            if(t[0] != tm[tm.length()-1]){
                flag = 0;
                break;
            }
        }
    }

    if(flag == 0)cout << "No" << endl;
    else cout << "Yes" << endl;
}