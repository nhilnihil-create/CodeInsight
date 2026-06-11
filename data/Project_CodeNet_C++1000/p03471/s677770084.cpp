#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
int main() {
    int N, Y;
    cin >> N >> Y;
    int n10 = -1, n5 = -1, n1 = -1;  
    for(int i = 0; i <= N; i++){
        for(int j = 0; j + i <= N; j++){
            int k = N - i - j;
            int total = 10000*i + 5000*j + 1000*k; 
            if(total == Y) {
                n10 = i;
                n5 = j;
                n1 = k;
            }
        }
    }
    cout << n10 << " " << n5 << " " << n1 << endl;
    return 0;
}