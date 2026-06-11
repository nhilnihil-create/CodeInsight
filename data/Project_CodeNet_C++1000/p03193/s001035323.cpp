#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;
typedef long long ll;

 
int main() {
    int N, H, W; cin >> N >> H >> W;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i];
    }
    int cnt=0;
    for(int i = 0; i < N; i++){
        if(A[i] >= H && B[i] >= W) cnt++;
    }
    cout << cnt << endl;
}