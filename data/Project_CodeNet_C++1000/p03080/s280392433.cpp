#include <bits/stdc++.h>
using namespace std;

int N;
string s;

int main(){
    cin >> N >> s;
    int count = 0;
    for(int i = 0; i < N; i++){
        if(s[i] == 'R'){
            count++;
        }
    }
    
    if(count > N - count){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
}