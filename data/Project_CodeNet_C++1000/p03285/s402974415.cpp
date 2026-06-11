#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    for(int i = 0; i <= 25; i++){
        int nokori = N - (4 * i);
        if(nokori >= 0 && nokori % 7 == 0){
            cout << "Yes" << endl;
            return 0;
        }
    }
    
    cout << "No" << endl;
    
}
