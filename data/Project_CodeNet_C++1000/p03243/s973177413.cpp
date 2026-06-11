#include <bits/stdc++.h>

using namespace std;

int main(){

    int num, a, b, c, stat = 0, temp;

    cin >> num;

    while(1){
        temp = num;
        a = temp % 10;
        temp /= 10;
        b = temp % 10;
        if(a == b){
            c = temp / 10;
            if(b == c){
                break;
            }
            else{
                num++;
            }
        }
        else{
            num++;
        }
    }

    cout << num << endl;

    return 0;
}
