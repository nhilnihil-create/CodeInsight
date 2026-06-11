#include<iostream>
#include<string>
using namespace std;
int main() {
    int N, T, A;
    int H[1100];
    cin >> N;
    cin >> T >> A;
    int x = 1;
    for(int i = 1; i <= N; i++)
        cin >> H[i];
    
    int min = ((1000*T -6*H[1]) - A*1000);
    if(min < 0) min = -min;
    for(int i = 1; i <= N; i++){
        int d = 1000*T -6*H[i] - A*1000;
        if(d < 0) d = -d;
        if(min >= d){
            min = d;
            x = i;
        }
    }
    cout << x << endl;
    return 0;
}