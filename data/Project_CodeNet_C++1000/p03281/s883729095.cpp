#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    if(N == 105){
        cout << 1 << endl;
    }
    else if(N < 105){
        cout << 0 << endl;
    }
    else{
        int count = 0;
        int total = 0;
        for(int j = 1; j <= N; j++){
            for(int i = 1; i <= N; i++){
                if(j % i == 0){
                    count++;
                }
            }
            if(count == 8){
                total++;
            }
            count = 0;
            j++;
        }
        cout << total << endl;
    }
}