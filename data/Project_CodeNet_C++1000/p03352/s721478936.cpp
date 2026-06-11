#include <bits/stdc++.h>
using namespace std;

int main(){

    int x;
    cin >> x;

    int i=2;
    int ans=1;
    int num;
    
    while(i*i<=x){
        num=i;
        while(num<=x){
            ans=max(ans,num);
            num*=i;
        }
        i++;
    }
    cout << ans << endl;
}