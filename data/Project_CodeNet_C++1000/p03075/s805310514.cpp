
#include <iostream>

using namespace std;

int main(){
    int i, j, k;
    int antenas[256];

    for(i=4;i>=0;i--){
        cin >> antenas[i];
    }
    cin >> k;

    for(i=0;i<5;i++){
        for(j=i;j<5;j++){
            if(antenas[i]-antenas[j]>k){
                cout << ":(" << endl;
                return 0;
            }
        }
    }
    cout << "Yay!" << endl;
    return 0;
}

