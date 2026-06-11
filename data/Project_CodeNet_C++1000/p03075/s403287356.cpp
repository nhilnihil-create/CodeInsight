#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> a(5);
    for(int i=0;i<5;i++){
        cin >> a[i];
    }

    int k;
    cin >> k;
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            if(k<abs(a[i]-a[j])){
                cout << ":(" << endl;
                return 0;
            }
        }
    }

    cout << "Yay!" << endl;
}