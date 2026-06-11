#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    int cR =0;
    int cB =0;
    char s;
    cin >> N;
    for(int i =0;i<N;++i){
        cin >> s;
        if(s =='R'){
            ++cR;
        }
        else if(s =='B'){
            ++cB;
        }
    }
    if(cR > cB){
        cout << "Yes" <<endl;
    }
    else {
        cout << "No" <<endl;
    }
}