#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    int entr[6], k, i, j, status = 0;
    for(i = 0; i < 5; i++)cin >> entr[i];
    cin >> k;
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++)if(abs(entr[i]-entr[j]) > k)status = 1;
    }
    if(!status)cout << "Yay!";
    else cout << ":(";
	return 0;
}