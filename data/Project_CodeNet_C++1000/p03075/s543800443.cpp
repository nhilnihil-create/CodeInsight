#include <bits/stdc++.h>

// # DEFINES # //
#define ll long long
#define M (ll)1e9+7
#define EPS 1e-9

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int arr[5];
    int k;

    for(int i = 0; i < 5; i++)
        cin >> arr[i];
    cin >> k;

    bool nconsegue = false;
    for(int i = 0; i < 5; i++) {
        for(int j = i+1; j < 5; j++) {
            if(abs(arr[i]-arr[j]) > k)
                nconsegue = true;
        }
    }
    if(nconsegue)
        cout << ":(" << endl;
    else 
        cout << "Yay!" << endl;

    return 0;
}