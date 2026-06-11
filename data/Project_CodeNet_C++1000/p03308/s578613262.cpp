#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++){
        cin >> a.at(i);
    }
    int max = 0;
    for(int i = 0;i < n;i++){
        for(int j = i + 1;j < n;j++){
            int memo = abs(a.at(i) - a.at(j));
            if(memo > max)max = memo;
        }
    }
    cout << max << endl;
}