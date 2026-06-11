#include <iostream>
using namespace std;
#define rep(i, n) for(int i=1;i<n;i++)

int main(){
    int num;
    cin >> num;
    int count=0, ans=0;
    rep(i, num+1){
        if(i%2 == 1){
            rep(j, i+1){
                if(i%j == 0){
                    count++;
                }
            }
            if(count == 8){
                ans++;
            }
            count=0;
        }
    }
    cout << ans << endl;
    return 0;
}