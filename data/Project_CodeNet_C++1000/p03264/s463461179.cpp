#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin >> k;
    vector<int> a(k);
    for(int i=0; i<k; i++) a.at(i) = i+1;
    int ans = 0;
    int count = k/2;
    if(k % 2 == 0){
        for(int i=0; i<k-1; i++){
            ans += count;
            if(i==0 || i%2==0){
                count--;
            }
        }
    }
    else {
        for(int i=0; i<k-1; i++){
            ans += count;
            if(i%2 != 0) count--;
        }
    }

    cout << ans << endl;
}