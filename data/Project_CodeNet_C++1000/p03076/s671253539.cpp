#include<vector>
#include <iostream>
#include<string>
#include <complex>

using namespace std;

int main(){
    int a[5];

    for(int i = 0;i < 5; i++){
        cin >> a[i];
    }

    int t = 0;
    int k = 0;
    int min = 9;
    int tar = 0;

    for(int i = 0; i < 5; i++){
        if(min > a[i]%10 && a[i] % 10 != 0){
            min = a[i]%10;
            tar = i;
        }
    }

    for(int i = 0; i < 5; i++){
        t += a[i];
        while(k < t && i != tar){
            k += 10;
        }
        t = k;
    }

    cout << t+a[tar] << endl;
}