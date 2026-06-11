#include<iostream>
#include<vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> card(N);
    int i,j;
    for(i=0;i<N;i++){
        cin >> card.at(i);
    }
    for(i=0;i<N;i++){
        for(j=0;j<N-i-1;j++){
            if(card.at(j)<card.at(j+1)){
                int swap = card.at(j);
                card.at(j) = card.at(j+1);
                card.at(j+1) = swap;
            }
        }
    }
    int alice = 0,bob = 0;
    for(i=0;i<N;i=i+2){
        alice += card.at(i);
    }
    for(i=1;i<N;i=i+2){
        bob += card.at(i);
    }
    cout << alice - bob << endl;
    return 0;
}