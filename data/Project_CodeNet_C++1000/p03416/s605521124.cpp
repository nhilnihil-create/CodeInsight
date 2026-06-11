#include <iostream>
using namespace std;

int main(void){
    int A,B;
    cin >> A >> B;
    int c[0];
    
    int counter = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                c[0] = i,c[4] = i;
                c[1] = j,c[3] = j;
                c[2] = k;
                int total_c;
                total_c = 10000*c[0] + 1000*c[1] + 100*c[2] + 10*c[3] + c[4];
                if(total_c >= A && total_c <= B){
                    counter++;
                }
            }
        }
    }
    
    cout << counter << endl;
    return 0;
}