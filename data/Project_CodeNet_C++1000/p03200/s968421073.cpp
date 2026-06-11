#include <bits/stdc++.h>
using namespace std;

int arr[200001];


int main(){
    
    string S;
    cin >> S;
    
    int n = S.size();
    for(int i = 0; i < n; i++){
        if(S[i] == 'W'){
            arr[i] = 1;
        }else{
            arr[i] = 0;
        }
    }
    stack<int>s;
    for(int i = 0; i < n; i++){
        //cout << i << " " << arr[i] << endl;
        s.push(arr[i]);
    }
    
    long long res = 0;
    int total_ones = 0;
    while(!s.empty()){
        int value = s.top();
        s.pop();
        if(value == 0){
            res += total_ones;
        }else{
            total_ones += 1;
        }
        //cout << value << " " << res << endl;
    }
    
    cout << res << endl;
    
    
}
