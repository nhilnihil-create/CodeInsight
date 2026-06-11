#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N,M,X;
    cin >> N >>M>>X;
    vector<int>vec(M);
    for(int i=0;i<M;i++){
        cin >>vec.at(i);
    }
    int B=0,Y=0;
    for(int i=0;i<M;i++){
        if(vec.at(i)<X){
            B++;
        }
        else if(vec.at(i)>X){
            Y++;
        }
    }
    cout <<min(B,Y)<<endl;
}