#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N + 1);
    int a;
    for(int i = 0; i < N; i++){
        cin >> a;
        A.at(a)++;
    }
    int b = 0;
    for(int i = 0; i < A.size(); i++){
        if(A.at(i) != 0){
            b++;
        }
    }
    int c = b - K;
    sort(A.begin(), A.end());
    int sum = 0;
    if(c > 0){
        for(int i = 0; i < A.size(); i++){
            if(A.at(i) != 0){
                sum += A.at(i);
                c--;
            }
            if(c == 0){
                break;
            }
        }
    }
    cout << sum << endl;
    return 0;
}