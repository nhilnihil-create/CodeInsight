#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    int time = 1900 * M + 100 * (N - M);
    int X = time * pow(2, M);
    cout << X << endl;
}