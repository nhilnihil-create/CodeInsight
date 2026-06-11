#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int min = 10000000;
    for(int i = 0; i < N; i++){
        int A;
        int min0 = 0;
        cin >> A;
        while(A % 2 == 0){
            A /= 2;
            min0++;
        }
        if(min0 < min){
            min = min0;
        }
    }
    cout << min << endl;
}