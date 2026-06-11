#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> d(N);
    for(int i=0;i<N;i++){
        cin >> d.at(i);
    }

    sort(d.begin(), d.end());
    reverse(d.begin(), d.end());
    int str = 101;
    int count = 0;
    for(int i=0;i<N;i++){
        if(str > d.at(i)){
            count++;
        }
        str = d.at(i);
    }
    cout << count << endl;
}