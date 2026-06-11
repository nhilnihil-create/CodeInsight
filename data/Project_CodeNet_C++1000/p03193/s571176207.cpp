#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,h,w;
    cin >> n >> h >> w;
    vector<int> height(n);
    vector<int> wide(n);
    for(int i = 0; i < n; i++){
        cin >> height.at(i) >> wide.at(i);
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        if(height.at(i) >= h && wide.at(i) >= w){
            count++;
        }
    }
    cout << count << endl;
}
