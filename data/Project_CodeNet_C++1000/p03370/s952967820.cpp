#include <iostream>
using namespace std;

int main(void){
    int N,X;
    cin >> N >> X;
    int D[N];
    int sum = 0;
    int min = 1010;
    for(int i = 0 ; i < N ; i++){
        cin >> D[i];
        sum += D[i];
        if(min > D[i]) min = D[i];
    }
    int answer;
    answer = (X - sum) / min;
    cout << answer+N << endl;
    return 0;
}
