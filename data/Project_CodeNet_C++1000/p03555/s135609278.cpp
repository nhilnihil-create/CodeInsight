#include <bits/stdc++.h>
using namespace std;
int main(void){
    string first,second;
    cin >> first >> second;
    reverse(second.begin(),second.end());
    if(first == second){
        cout << "YES";
    }else{
        cout << "NO";
    }
}