#include<iostream>

using namespace std;

int main(){
    int n,time;
    cin >> n >> time;
    int *c = new int[n];
    int *t = new int[n];
    for(int i = 0; i < n; i++){
        cin >> c[i] >> t[i];
    }
    
    int cost = 1001;
    for(int i = 0; i < n; i++){
        if(t[i] <= time){
            if(cost > c[i]){
                cost = c[i];
            }
        }
    }
    if(cost == 1001){
        cout << "TLE" << endl;
    }else{
        cout << cost << endl;
    }


    delete[] c;
    delete[] t;
    return 0;
}