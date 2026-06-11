#include <iostream>
using namespace std;
int N;
int A[200];

int main(){
    int A, B, C, X;
    cin>>A>>B>>C>>X;
    int count;
    for(int a = 0; a <= A; a++){
        for(int b = 0; b <= B; b++){
            for(int c = 0; c <= C; c++){
                if(500*a + 100*b + 50*c == X) count++;
            }
        }
    }
    cout << count << endl;
}
