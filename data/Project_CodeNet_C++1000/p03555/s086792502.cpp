#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    string s,t;
    cin >> s >> t;
    int ans=0;
    if(s[0]==t[2]){
        if(s[1]==t[1]){
            if(s[2]==t[0]){
                ans=1;
            }
        }
    }
    cout << (ans ? "YES":"NO") << endl;
}
