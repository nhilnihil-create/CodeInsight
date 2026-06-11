#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> vec(N);
    int count=0, value;
    for(int i=0; i<N; i++){
        cin >> vec.at(i);
    }
    sort(vec.begin(), vec.end());
    reverse(vec.begin(),vec.end());
    value = vec.at(0);
    count++;
    for(int x: vec){
        if(x != value){
            count++;
            value = x;
        }
    }
    cout << count << endl;
}