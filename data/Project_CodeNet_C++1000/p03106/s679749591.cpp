#include <bits/stdc++.h>
using namespace std;

int main(void){
    int A,B,K;
    cin >> A >> B >> K;
    vector<int> n;
    for(int i = 1 ; i <= 100 ; i++){
        if(A % i == 0 && B % i == 0){
            n.push_back(i);
        }
    }
    sort(n.begin(),n.end(),greater<int>());
    cout << n[K-1] << endl;
    return 0;
}