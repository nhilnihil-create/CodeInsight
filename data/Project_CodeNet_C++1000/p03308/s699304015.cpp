#include <iostream>
using namespace std;

int main(void){
    int N;
    cin >> N;
    int data[N];
    int max = 0;
    int min = 1000000000;
    for(int i = 0; i < N ; i++){
        cin >> data[i];
        if(max < data[i]) max = data[i];
        if(min > data[i]) min = data[i];
    }
    cout << max - min << endl;
    return 0;
}