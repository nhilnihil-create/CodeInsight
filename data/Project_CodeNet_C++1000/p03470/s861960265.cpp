#include<bits/stdc++.h>
using namespace std;

int main () {
    int N;
    cin >> N;
    vector <int> d(N);
    for (int i=0; i<N; i++) {
        cin >> d.at(i);
    }

    sort (d.begin(), d.end());
    int sum=1;

    for (int i=0; i<N-1; i++) {
        if (d.at(i)<d.at(i+1)) {
            sum++;
        }
        else {
            sum+=0;
        }        
    }
    cout << sum << endl;
}

    

  
    
