#include <iostream>
using namespace std;
int main(void){
    int N;
    cin >> N;
    int a[N];
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    int ans = 0;
    for(int i=0;i<N;i++){
        while(a[i] % 2 == 0){
            ans++;
            a[i] = a[i] / 2;
        }
    }
    
    cout << ans << endl;
}
