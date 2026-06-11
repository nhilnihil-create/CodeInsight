#include<bits/stdc++.h>
#include<climits>
using namespace std;


int main(void){
    // Your code here!
    int N;
    cin >> N;
    int A;
    int sum = 1;
    int pw = 1;
    for(int i = 0; i <N;i++){
        cin >> A;
        if(A%2==0)sum *= 2;
        pw *= 3;
    }
    cout << pw - sum << endl;
    
    
    

}
