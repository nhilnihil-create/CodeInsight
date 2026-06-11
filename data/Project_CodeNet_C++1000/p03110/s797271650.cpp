#include <bits/stdc++.h>
using namespace std;

int main(void){
    
    int N;
    float total = 0;
    cin >>N;
    
    for(int i=0;i<N;i++){
        float x_i;
        string u_i;
        cin >> x_i >> u_i;
        
        if(u_i == "JPY"){
            total += x_i;
        }
        else{
            total += (x_i * 380000.0); 
        }
    }
    cout << total << endl;
}