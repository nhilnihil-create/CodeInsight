#include <bits/stdc++.h>
 
using namespace std;

int main(){
    int antenas[5], k;
    for(int i = 0; i < 5; i ++){
        cin >> antenas[i]; 
    }
    cin >> k;
    for(int i =1;i < 5; i++){
        for(int j =0 ;j < 5; j++){
            if(antenas[i] - antenas[j] > k){
                cout << ":("<<endl;
                return 0;
            }

        }

    }
    cout << "Yay!" <<endl;
}