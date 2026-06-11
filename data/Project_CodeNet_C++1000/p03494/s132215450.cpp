#include <bits/stdc++.h>
using namespace std;

int main () {
    int N;
    cin >> N;

    vector<int>A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    int count = 0;
    bool shift = true;

    while(true){
        for(int i = 0; i < N; i++){
            if(A.at(i) % 2 == 0)
                A.at(i) = A.at(i) / 2;
            else {
                shift = false;
                break;
            }
        }

        if(shift == false) break;
        count++;

    } 
    cout << count << endl;
}