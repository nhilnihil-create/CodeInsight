#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <utility>
#include <numeric>

using namespace std;

int main(){

    int N;
    cin >> N;
    vector<int> L(N);

    for(int i =0; i < N; i++){
        cin >> L[i];
    }

    sort(L.begin(), L.end());

    int lenSum = accumulate(L.begin(), L.end() - 1, 0);
    if(L[N - 1] < lenSum){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    return 0;
}