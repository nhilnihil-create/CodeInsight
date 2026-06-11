#include <iostream>
using namespace std;
int main(void){
    
    
    int antena[5];
    int K;
    for(int i = 0; i < 5; i++){
        cin >> antena[i];
    }
    cin >> K;
    
    for(int i = 0; i < 5; i++){
        for(int j = i + 1; j < 5; j++){
            if(K < antena[j] - antena[i]){
                cout << ":(" << endl;
                return 0;
            }
        }
    }
    
    cout << "Yay!" << endl;
    
}
