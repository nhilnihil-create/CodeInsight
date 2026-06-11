#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    for(int i = N; i <= 999; i++){
        if(i % 111 == 0){
            cout << i << endl;
            return 0;
        }
    }
}