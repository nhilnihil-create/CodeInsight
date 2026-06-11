#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef  long long ll;

int main(void){
    string s;
    int price = 700;
    cin >> s;

    if(s[0] == 'o')
        price += 100;
    if(s[1] == 'o')
        price += 100;
    if(s[2] == 'o')
        price += 100;

    cout << price << endl;

    return 0;
}