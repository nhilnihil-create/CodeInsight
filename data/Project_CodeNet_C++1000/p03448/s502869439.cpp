#include <bits/stdc++.h>
using namespace std;

int main(){
    int A;
    int B;
    int C;
    int X;

    cin >> A >> B >> C >> X;

    int counter = 0;
    for(int i = 0; i <= A; i++){
        for(int j = 0; j <= B; j++){
            for(int k = 0; k <= C; k++){
                int sum = 500*i + 100*j + 50*k;
                if(sum == X)
                    ++counter;
            }
        }
    }

    cout << counter << endl;

    return 0;
}