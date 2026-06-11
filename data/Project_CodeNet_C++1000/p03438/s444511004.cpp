#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    long long N;
    cin >> N;
    vector<long long> a(N), b(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i< N; i++)cin >> b[i];
    for(int i = 0; i < N; i++){
        if((b[i] - a[i]) % 2 == 1){
            a[i] += 2;
            b[i] += 1;
        }
    }
    long long res = 0, res2 = 0;
    for(int i = 0; i < N; i++){
        if(b[i] > a[i]) res += b[i] - a[i];
        else res2 += a[i] - b[i];
    }
    if(res2 * 2 > res){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
}