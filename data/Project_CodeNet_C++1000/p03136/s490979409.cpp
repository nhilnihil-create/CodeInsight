#include<iostream>
#include<vector>

using namespace std;

int main(){

    int N;
    vector<int> L;
    int max = -1;
    int idx = 0;
    cin >> N;
    L.resize(N);
    for (int i = 0; i < N; i++){
        cin >> L[i];
        if(L[i] > max){
            max = L[i];
            idx = i;
        }
    }
    int sum = 0;
    for (int i = 0; i < N; i++){
        if(i==idx){
            continue;
        }
        sum += L[i];
    }

    if(sum > max){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}