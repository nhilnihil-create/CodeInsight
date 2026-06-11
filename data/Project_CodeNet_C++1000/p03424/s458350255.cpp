#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >> N;
    char S[N];
    string num = "Three";
    for(int i=0;i<N;i++){
        cin >> S[i] ;
        if(S[i] == 'Y'){
            num = "Four";
        }
    }
    cout << num <<endl;
}