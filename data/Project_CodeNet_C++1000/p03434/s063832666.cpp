#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
int main() {
    int N;
    cin >> N;
    int a;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin >> a;
        A.at(i) = a;
    }
    sort(A.begin(), A.end() );
    reverse(A.begin(), A.end());
    int sum_A,sum_B;
    sum_A =0;
    sum_B =0;
    for(int i=0;i<N;i++){
        if(i%2==0){
            sum_A = sum_A + A.at(i) ;
        }
        else{
            sum_B = sum_B + A.at(i) ;
        }
    }
    cout << sum_A - sum_B << endl;
}