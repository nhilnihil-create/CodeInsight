#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
int main() {
    int N;
    int d[110];
    int c = 0;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> d[i];
    sort(d, d+N, greater<int>());
    for(int i = 0; i < N; i++){
        if(d[i] == d[i + 1]) continue;
        c++;
    }
    cout << c << endl;
    
    return 0;
}