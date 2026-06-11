#include <bits/stdc++.h>
using namespace std;
 
int main() {
        int N;
        int A;
        cin >> N;
        int MAX = 1000000;
        for(int i = 0; i < N; i++){
        int wattakaisu = 0;
        cin >> A;
        while(A % 2 == 0){
                A /= 2;
           wattakaisu += 1;
        }
        if(MAX > wattakaisu){
                 MAX = wattakaisu;
        }
    }
    cout << MAX << endl;
}