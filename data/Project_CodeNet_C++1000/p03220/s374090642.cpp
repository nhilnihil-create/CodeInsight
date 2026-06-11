#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
int main() {
    int N;
    double T,A;
    cin >> N;
    cin >> T >> A;
    vector<int> H(N);
    for(int i=0;i<N;i++){
        cin >> H.at(i) ;
    }
    vector<double> temp(N) ;
    for(int i=0;i<N;i++){
        temp.at(i) = T -(H.at(i))*0.006 ;
    }
    int suitable_price ;
    double min_differ = 9999999;
    double diff;
    for(int i=0;i<N;i++){
        if(A > temp.at(i)){
            diff = A - temp.at(i) ;
            if(diff < min_differ){
                min_differ = diff;
                suitable_price = i+1;
            }
        }
        else{
            diff = temp.at(i) - A;
            if(diff < min_differ){
                min_differ = diff;
                suitable_price = i+1;
            }
        }
    }
    cout  << suitable_price << endl;
}