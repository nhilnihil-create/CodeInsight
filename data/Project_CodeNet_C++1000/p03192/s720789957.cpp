#include <bits/stdc++.h>
using namespace std;
int main(){
    string N; cin >> N;
    int count = 0;
    for(int i = 0; i < 4; i++){
        if(N[i] == '2') count++; 
    }
    cout << count << endl;
    return 0;
}