#include<bits/stdc++.h>
using namespace std; //std::の省略のため
using ll = long long;

int main(){
    int N;
    cin >> N;

    int A[N];
    for(int i = 0; i<N; i++) cin >> A[i];

    bool judge = true;
    int count = 0;

    while(judge){
        judge = true;

        for(int i = 0; i<N; i++){
            if(A[i] % 2 != 0) judge = false;
            else A[i] /= 2;
        }

        if(judge){
            count++;
        }
    }

    cout << count << endl;
    
}