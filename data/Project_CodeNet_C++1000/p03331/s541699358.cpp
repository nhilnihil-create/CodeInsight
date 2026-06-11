#include <iostream>
using namespace std;

int get_sum(int i){
    int sum = 0;
    while(i > 0){
        sum += i % 10;
        i /= 10;
    }
    return sum;
}

int main(){
    int N, min = 1000001;
    cin >> N;
    for(int i = 1; i <= N - 1; i++){
        int j = N - i;
        if(1 <= j && j <= N && i + j == N && min > get_sum(i) + get_sum(j)) min = get_sum(i) + get_sum(j);
    }
    cout << min << endl;
}