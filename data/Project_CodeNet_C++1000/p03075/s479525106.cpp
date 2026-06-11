#include<iostream>

using namespace std;

int main()
{
    int antena[5],i,j;
    int k;
    for(i=0; i<5; i++){ cin >> antena[i]; }
    cin >> k;
    for(i=0; i<4;i++) {
        for(j=i+1; j<5; j++){
            if(antena[j]-antena[i]>k){
                cout << ":(" << endl;
                return 0;
            }
        }
    }
    cout << "Yay!" << endl;
    return 0;
}