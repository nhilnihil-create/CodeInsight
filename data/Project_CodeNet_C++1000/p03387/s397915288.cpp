#include<bits/stdc++.h>
using namespace std;

int main() {
    vector <int> abc(3, 0);
    cin >> abc.at(0) >> abc.at(1) >> abc.at(2);
    sort(abc.begin(), abc.end());
    long long ans=0;
    if ((abc.at(1)-abc.at(0))%2==0) {
        ans += (abc.at(1)-abc.at(0))/2; 
        ans += abc.at(2)-abc.at(1);
    }
    else {
        abc.at(0)++;
        abc.at(2)++;
        ans++;
        ans += (abc.at(1)-abc.at(0))/2; 
        ans += abc.at(2)-abc.at(1);
    }
    cout << ans;
}