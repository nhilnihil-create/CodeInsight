#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    int A;
    cin >> N;
    int NArray[N];
    for (int i=0; i < N; i++){
        cin >> A;
        NArray[i] = A;
    }

    sort(NArray, NArray + N);
    
    cout << NArray[N-1] - NArray[0] << endl;

}