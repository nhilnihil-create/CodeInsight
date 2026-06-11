#include <iostream>
#include <stdio.h>
#include <vector> 
using namespace std;

int countOdd(vector<int> array) {
    int count = 0;
    for (int j = 0; j < array.size(); j++) {
        while(array[j] % 2 == 0) {
            array[j] /= 2;
            count++;
        }
    }
    return count;
}

int main(void){
    int N; cin >> N;
    int i=0;

    vector<int> a(N);

    while(N > i){
        cin >> a[i];
        i++;
    }
    cout << to_string(countOdd(a)) << endl;
}


