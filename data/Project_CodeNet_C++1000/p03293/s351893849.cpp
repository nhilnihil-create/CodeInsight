#include <iostream>
#include<string>
#include<stdio.h>
using namespace std;

int main(){
    int n;
    string s,ans;
    string word="n";
    cin >> s;
    cin >> ans;
    n=s.size();
    string str=s+s;
    for(int i=0;i<n;i++){
        for(int j=i;j<n+i;j++){
            if(str[j]!=ans[j-i]){
                break;
            }
            if(j==n+i-1){
                cout << "Yes";
                exit(0);
            }
        }
    }
    cout << "No";
}