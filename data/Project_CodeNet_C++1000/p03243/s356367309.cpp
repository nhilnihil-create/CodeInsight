#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a = n/100;
    if(n>a*100+a*10+a) a++;
    cout << a*100+a*10+a << endl;
    return 0;
}