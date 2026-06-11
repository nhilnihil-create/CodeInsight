#include<iostream>
#include<vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> d(N);
    int i,j;
    for(i=0;i<N;i++){
        cin >> d.at(i);
    }
    for(i=0;i<N;i++){
        for(j=0;j<N-i-1;j++){
            if(d.at(j) < d.at(j+1)){
                int swap = d.at(j);
                d.at(j) = d.at(j+1);
                d.at(j+1) = swap;
            }
        }
    }
    int count = 1;
    for(i=0;i<N-1;i++){
        if(d.at(i) > d.at(i+1)){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}