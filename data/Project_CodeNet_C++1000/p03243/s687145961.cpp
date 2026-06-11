#include <bits/stdc++.h>
using namespace std;
int main(){
    long long s, i;
    cin >> s;
    for(i=s;i<=999;i++){
        if(i%111==0){
            cout << i <<endl;
            return 0;
        }
    }

    return 0;
}
