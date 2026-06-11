#include<bits/stdc++.h>
using namespace std;
int intEqual(int i, int j, int k){
    if (i == j){
        return  k; 
    } else if (j == k)
    {
        return i;
    } else {
        return j;
    }
}
int main(){
    int A, B, C;
    cin >> A >> B >> C;
    cout << intEqual(A, B, C) << endl;
    
}