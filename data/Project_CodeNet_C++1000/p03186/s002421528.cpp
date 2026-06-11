#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll a,b,c;
    cin >> a >> b >> c;
    ll count ;

    if(0<=a+b-c){
        count=b+c;
    }
    else if(c>a+b){
        count=a+2*b+1;
    }
    cout << count << endl;
    return 0;

}