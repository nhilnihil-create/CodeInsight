#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    int cnt = 0;
    while(1){
        int flag = 0;
        for(int i = 0; i < N; i++){
            if(A[i] % 2 != 0) flag = 1;
            else A[i] /= 2;
        }
        if(flag == 1) break;
        cnt++;
    }
    cout << cnt << endl;
}