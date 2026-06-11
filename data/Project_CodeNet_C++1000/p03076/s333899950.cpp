#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[5];

    int max = 0;
    int index = 0;
    for(int i=0; i<5; i++){
        cin>>a[i];
        if(a[i]%10 == 0) continue;
        if(max <= 10 - a[i]%10){
            max = 10 - a[i]%10;
            index = i;
            //cout <<"aa" << max << endl;
        }
    }

    int sum = 0;
    for(int i=0; i<5; i++){
        if(i == index){
            sum += a[i];
            //cout << "-" << a[i] << endl;
        }else{
            sum += ((a[i]-1)/10 + 1)*10;
           // cout <<sum << endl;
        }
    }
    cout << sum << endl;
}

