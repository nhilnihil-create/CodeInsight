#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int X;
    cin >>X;
    int ans=1;
    for(int b=2;b<=X;b++){
        int power=b*b;
        for(int p=2;;p++){
            if(power>X){
                break;
            }
            ans=max(ans,power);
            power*=b;
        }
    }
    cout <<ans<<endl;
}