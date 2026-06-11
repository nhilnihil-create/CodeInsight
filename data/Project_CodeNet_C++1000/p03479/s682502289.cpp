#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int x,y,cnt=1;
    cin >> x >>y;
    while(x*2<=y){
        cnt++;
        x*=2;
    }
    cout << cnt << endl;
}