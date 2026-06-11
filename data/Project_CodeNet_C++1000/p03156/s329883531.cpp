#include <iostream>
using namespace std;

int main(){
    int N, A, B;
    cin >> N >> A >> B;

    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0; i < N; i++){
        int P; cin >> P;
        if (P <= A){
            c1 ++;
        }else if(P <= B){
            c2 ++;
        }else{
            c3 ++;
        }
    }

    cout << min(c1, min(c2, c3)) << endl;
    

    return 0;
}