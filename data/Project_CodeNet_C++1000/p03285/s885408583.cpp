#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, answer;
    cin >> N;
    answer = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if((4 *(i) + 7 *(j)) == N ){
                answer++;
            }
        }
    }
    if(answer > 0){
        cout << "Yes" << endl;
    }
    else if(answer == 0){
        cout << "No" << endl;
    }
}