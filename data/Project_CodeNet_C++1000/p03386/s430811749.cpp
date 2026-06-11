#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,k;
    cin >> a >> b >> k;
    for(int i=a;i<b+1;i++)if(i<a+k || i>=b-k+1)cout << i << endl;
}