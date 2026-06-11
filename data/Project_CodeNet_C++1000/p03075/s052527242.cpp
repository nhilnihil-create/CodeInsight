#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    vector<int> a(5);
    for(int i = 0; i < 5; i++) cin >> a[i];
    int k;
    cin >> k;
    for(int i = 0; i < 4; i++){
        for(int  j = 0; j < 5; j++){
            if(i == j) continue;
            if(abs(a[i]-a[j]) > k){
                cout << ":(" << endl;
                return 0;
            }
        }
    }
    cout << "Yay!" << endl;
    return 0;
}