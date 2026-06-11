#include <iostream>
#include<vector>
#include<math.h>
using namespace std;

typedef pair<int,long long> p;

int main(){
    string S;
    long long K;
    cin >> S;
    cin >> K;
    for(int i=0;i<K;i++){
        if(S[i]!='1'){
            cout << S[i];
            exit(0);
        }
    }
    cout << '1';
}