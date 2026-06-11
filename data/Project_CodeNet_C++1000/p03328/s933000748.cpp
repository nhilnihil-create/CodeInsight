#include<bits/stdc++.h>
using namespace std;
int main(){
    long a,b;
    cin >> a >> b;
    long ans=0;
    long t=b-a;
    long res=0;
    res=(1+t)*t/2;
    cout << res-b << endl;
    return 0; 
}