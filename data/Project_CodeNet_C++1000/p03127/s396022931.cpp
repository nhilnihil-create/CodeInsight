#include <iostream>
#include <vector>
using namespace std;
int gcd(int x, int y){
    if(x < y) swap(x, y);
    if(x % y == 0) return y;
    return gcd(y, x % y);
}
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    int g = A[0];
    for(int i = 1; i < N; i++){
        g = gcd(g, A[i]);
    }
    cout << g << endl;
}