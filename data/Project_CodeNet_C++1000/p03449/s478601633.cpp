#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a1(n),a2(n);
    for(int i=0; i<n; i++){
        cin >> a1.at(i);
    }
    for(int i=0; i<n; i++){
        cin >> a2.at(i);
    }

    int candies,ans=0;

    for(int i=0; i<n; i++){
        candies=0;
        for(int j=0; j<=i; j++){
            candies+=a1.at(j);
        }
        for(int j=i; j<n; j++){
            candies+=a2.at(j);
        }
        ans=max(ans,candies);
    }

    cout << ans << endl;
}