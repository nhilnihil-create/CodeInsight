#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    long long int entr[6], temp[7], i, n, count = 0;
    cin >> n;
    for(i = 0; i < 6; i++)temp[i] = 0;
    temp[0] = n;
    for(i = 0; i < 5; i++)cin >> entr[i];
    while(1){
        if(temp[5] != 0)break;
        for(i = 5; i > 0; i--){
            if(temp[i-1] >= entr[i-1]){
                temp[i] += entr[i-1];
                temp[i-1] -= entr[i-1];
            }else{
                temp[i] += temp[i-1];
                temp[i-1] = 0;
            }
        }
        count++;
    }
    if(temp[5] != n){
        count += (n/(temp[5]));
        if(!(n%temp[5]))count--;
    }
    cout << count;
	return 0;
}