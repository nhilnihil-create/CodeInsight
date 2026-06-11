#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0 ; i < N ; i++){
        int tmp;
        int cnt = 0;
        cin >> tmp;
        
        while(tmp % 2 == 0){
            tmp /= 2;
            cnt++;
        }
        
        A.at(i) = cnt;
    }
    
    int min = 1000000010;
    for(int i = 0 ; i < N ; i++){
        if(A.at(i) < min){
            min = A.at(i);
        }
    }
    
    cout << min << endl;
    return 0;
    
}