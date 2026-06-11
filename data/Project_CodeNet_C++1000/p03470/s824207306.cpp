#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> d(n);
    for(int i = 0;i < n;i++)cin >> d.at(i);
    int count = 1;
    sort(d.begin(), d.end());
    for(int i = 1;i < n;i++){
        if(d.at(i - 1) < d.at(i))count++;
    }
    cout << count << endl;
}