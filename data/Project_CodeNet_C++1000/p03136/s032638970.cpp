#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> length(N);
    for(int i=0; i<N; i++){
        cin >> length.at(i);
    }
    int M=0;
    for(int j=0; j<N; j++){
        if(M<length.at(j)){
            M=length.at(j);
        }
    }
    int sum=0;
    for(int k=0; k<N; k++){
        sum+=length.at(k);
    }

    sum-=M;

    if(sum > M){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    
}