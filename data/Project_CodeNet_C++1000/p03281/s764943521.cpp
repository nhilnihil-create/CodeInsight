#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    int num_8yaku = 0;
    int num_yaku = 2;

    for(int i = 1; i<N+1; i=i+2){
        for(int j = 3; j<i; j=j+2){
            if(i%j==0){
                num_yaku = num_yaku+1;
            }
        }
        if(num_yaku == 8){
            num_8yaku++;
        }
        num_yaku = 2;
    }

    cout << num_8yaku << endl;
    return 0;

} 
