#include <bits/stdc++.h>          
using namespace std;               

int main() {

    //input
    int N;
    cin >> N;
    vector<int> card(N);
    for (int i=0; i<N; i++) {
        cin >> card.at(i);
    }

    int A=0;
    int B=0;
    sort(card.begin(),card.end(),greater<int>());
    for (int i=0; i<N; i++) {
        if (i%2 == 0) {
            A += card.at(i);
        }
        else {
            B += card.at(i);
        }
    }
    
    cout << A-B << endl;
}