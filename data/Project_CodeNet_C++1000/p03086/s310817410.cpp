#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;

    int ans = 0;
    int count = 0;
    for(char c : S){
        if ( c == 'A' || c == 'C' || c == 'G' || c == 'T'){
            count += 1;
        }else{
            if(ans < count){
                ans = count;
            }
            count = 0;
        }
    }

    if(ans < count){ans = count;}

    cout << ans << endl;

    return 0;
}