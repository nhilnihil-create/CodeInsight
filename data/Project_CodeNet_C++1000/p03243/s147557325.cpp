#include <iostream>
using namespace std;
int main(void){
    int n; cin >> n;
    int ichi = n % 10;
    int ju = (n % 100 - ichi) / 10;
    int hyaku = (n - ju * 10 - ichi) / 100;
    int judge = hyaku * 100 + hyaku * 10 + hyaku;
    int ans = n;
    if(ichi != ju || ju != hyaku || hyaku != ichi){
        if(judge < n){
            ans = (hyaku + 1) * 100 + (hyaku + 1) * 10 + (hyaku + 1);
        }else{
            ans = judge;
        }
    }
    cout << ans << endl;
    return 0;
}