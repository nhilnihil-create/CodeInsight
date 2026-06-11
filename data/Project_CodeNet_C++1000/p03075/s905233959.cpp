#include<iostream>
#include<stdbool.h>
#include<vector>
using namespace std;

int main(){
    vector<int> a(5);
    for(int i = 0; i<5; i++){
    cin >> a[i]; 
    }
    int k;
    cin >> k;
    if(a[4]-a[0]<=k){
        cout << "Yay!";
    }
    else{
        cout << ":(";
    }

}