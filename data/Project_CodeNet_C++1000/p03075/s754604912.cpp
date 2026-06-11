#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){

    int n[5];
    int k;
    int r;


    for(int i=0; i<5;i++){
        cin >> n[i];
    }

    cin >> k;

    int flag = 0;

    for(int i=0; i<5;i++){
        for(int j=0; j<5; j++){

            if(n[i] - n[j] < 0){
                r = n[j]-n[i];
            } else {
                r = n[i]-n[j];
            }

            if(r > k){
                flag = 1;
            }
        }
    }

    if(flag == 1){
        cout << ":(" << endl;
    } else {
        cout << "Yay!" << endl;
    }

}