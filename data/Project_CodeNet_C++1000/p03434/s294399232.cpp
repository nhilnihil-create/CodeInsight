#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >> N;
    
    vector<int> vec(N);
    for(int i = 0; i < N; i++){
        cin >> vec.at(i);
    }

    //sort algorithm
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(vec.at(i) > vec.at(j)){
                int A = vec.at(i);
                int B = vec.at(j);
                vec.at(j) = A;
                vec.at(i) = B;
            }
        }
    }
    
    int sum = 0;
    for (int i = 0; i < N; i+=2){
        sum += vec.at(i);
    } 
    for (int i = 1; i < N; i+=2){
        sum -= vec.at(i);
    } 

    cout << sum << endl;



}