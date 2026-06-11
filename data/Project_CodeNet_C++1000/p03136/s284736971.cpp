#include <bits/stdc++.h>
using namespace std;

int main(){
    int N ;
    cin >> N;
    vector<int> L(N);
    int max = -1;
    int sum = 0;
    int num = 0;

    for(int i = 0;i < N; i++){
        cin >> num;
        // L.at(i) = num;
        if(max < num){
            max = num;
        }
        sum += num;
    }

    if(max < sum - max){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

}