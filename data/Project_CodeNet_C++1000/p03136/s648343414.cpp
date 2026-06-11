#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int>l(N);

    for(int i=0; i<N; i++){
        cin >> l[i];
    }

    sort(l.begin(), l.end());

    int longest = l[l.size()-1], others=0;

    for(int i=0; i<l.size()-1; i++){
        others += l[i];
    }

    if(longest < others ){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }



    return 0;
}