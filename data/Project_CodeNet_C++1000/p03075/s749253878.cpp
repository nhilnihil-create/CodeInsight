#include <bits/stdc++.h>
using namespace std;

int main(void){
 
    int a,b,c,d,e,k;
    cin >> a >> b >> c >> d >> e >> k;
    
    if(max({abs(a-b),abs(a-c),abs(a-d),abs(a-e),abs(b-c),abs(b-d),abs(b-e),abs(c-d),abs(c-d),abs(d-e)}) <= k){
        cout << "Yay!" <<endl;
    }
    else{
        cout << ":(" << endl;
    }
}