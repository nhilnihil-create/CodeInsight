#include<iostream>
#include<string>
using namespace std;
int main() {
    int N, X;
    cin >> N >> X;
    int m[110];
    int sum = 0;
    for(int i = 0; i < N; i++){
        cin >> m[i];
        sum += m[i]; 
    }
    int min = m[0];
    for(int i = 0; i < N; i++){
        if(min > m[i])
            min = m[i];
    }
    int R, j;
    R = X - sum;
    j = R / min;
    cout << N + j << endl;
    return 0; 
}