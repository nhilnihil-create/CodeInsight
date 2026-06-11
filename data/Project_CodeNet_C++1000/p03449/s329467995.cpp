// C Candies
#include <bits/stdc++.h>
using namespace std;

vector<int> input(int N){
    vector<int> vec;    
    int temp = 0;
    for (int i = 0; i < N; i++ )    {
        cin >> temp;
        vec.push_back(temp);
    }
    return vec;
}


int main(){
    int N; // 100
    cin >> N;
    vector<int> a1 = input(N); // max 100
    vector<int> a2 = input(N);
    vector<int> b1 = vector<int>(N);
    vector<int> b2 = vector<int>(N);

    b1.at(0) = a1.at(0);
    b2.at(0) = a2.at(0);
    for(int i = 0; i < N-1; i++)    {
        b1.at(i+1) = b1.at(i) + a1.at(i+1);
        b2.at(i+1) = b2.at(i) + a2.at(i+1);
    }
  
    int max_val = 0;
    // zero
    int value = b1.at(0) + b2.at(N-1);
    max_val = value;
    for (int i = 0; i < N-1; i++) {
        int value = b1.at(i+1) - b2.at(i) + b2.at(N-1);
        if (value > max_val){
            max_val = value;    
        }
    }
    cout << max_val << endl;
}