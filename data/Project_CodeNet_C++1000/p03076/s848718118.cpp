#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
    int entr[6], i, count, menor = INT_MAX;
    for(i = 0; i < 5; i++)cin >> entr[i];
    sort(entr, entr+5);
    do{
        count = 0;
        for(i = 0; i < 5; i++){
            while(count%10 != 0)count++;
            count += entr[i];
        }
        menor = min(menor, count);
    }while(next_permutation(entr, entr+5));
    cout << menor;
	return 0;
}