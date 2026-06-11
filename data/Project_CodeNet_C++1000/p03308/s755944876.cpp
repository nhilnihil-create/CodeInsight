#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N) ;
    for(int i=0;i<N;i++){
        cin >> A.at(i) ;
    }
    int diff ;
    int max_diff=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if((A.at(i)) > (A.at(j))){
                diff = (A.at(i)) - (A.at(j));
                if(diff > max_diff){max_diff = diff ;}
            }
            else{
                diff = (A.at(j)) - (A.at(i));
                if(diff > max_diff){max_diff = diff ;}
            }
        }
    }
    cout << max_diff << endl;
}