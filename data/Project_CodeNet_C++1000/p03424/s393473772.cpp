#include <bits/stdc++.h>
#include<iostream>
using namespace std;
 
int main() {
    int n;

    cin >> n;
    map<string,int>a;
    for(int i = 0;i < n;i++){
        string s;
        cin >> s;
        a[s] = 1;
    }
    if(a.size() == 3){
        cout << "Three";
    }else{
        cout << "Four";
    }
}
   
