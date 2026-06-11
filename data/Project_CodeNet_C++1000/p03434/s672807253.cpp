#include <bits/stdc++.h>
using namespace std;

int main(){
    int N ;
    cin >> N;
    vector<int> num(N);
    for(int i = 0 ; i < N; i++){
        cin >> num.at(i);
    }
    sort(num.begin(), num.end());
    reverse(num.begin(), num.end());

    int alice = 0;
    int bob = 0;
    bool aliceFlag = true;
    for(int n : num){
        if(aliceFlag == true){
            alice += n;
            aliceFlag = false;
        }else{
            bob += n;
            aliceFlag = true;
        }

    }

    cout << alice - bob << endl;
}