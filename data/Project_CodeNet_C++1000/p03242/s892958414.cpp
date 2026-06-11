#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a,b,c;
    a=n/100;
    b=(n/10)%10;
    c=n%10;
    if(a==9) cout << 1; 
    else cout << 9 ;   
    if(b==9) cout << 1;
    else cout << 9 ;
    if(c==9) cout << 1 <<endl;
    else cout << 9 << endl;

}