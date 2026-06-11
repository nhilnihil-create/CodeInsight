#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    
    vector<int> size(110,0);
    for(int i = 0 ; i < N ; i++){
        int tmp;
        cin >> tmp;
        size.at(tmp)++;
    }
    
    int cnt = 0;
    for(int i = 0 ; i < 110 ; i++){
        if(size.at(i) != 0){
            cnt++;
        }
    }
    
    cout << cnt << endl;
}