#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N, H;
    cin >> N >> H;
    int a_max = 0; 
    int b[N];
    for(int i=0; i<N; i++){
        int a;
        cin >> a >> b[i];
        a_max = max(a, a_max);
    } 
    int cnt = 0;
    sort(b, b + N, greater<int>());
    for(int i=0; i<N && H > 0 && b[i] > a_max; i++){
        H -= b[i];
        cnt++;
    }
    if(H > 0){
        cnt += (H - 1) / a_max + 1;
    }
    cout << cnt << endl;
    return 0;
}