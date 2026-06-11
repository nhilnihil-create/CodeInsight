/*
      author : nishi5451
      created: 11.08.2020 20:26:43
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    if(n>999){
        n-=999;
        char a = '0' + n/100;
        char b = '0' + (n%100)/10;
        char c = '0' + (n%10);
        cout << "ABD" << endl;
    }  
    else{
        char a = '0' + n/100;
        char b = '0' + (n%100)/10;
        char c = '0' + (n%10);
        cout << "ABC" << endl;
    }
    return 0;
}